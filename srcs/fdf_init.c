/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_init_subj(t_fdf *fdf)
{
	fdf->ang_x = 0;
	fdf->ang_y = 0;
	fdf->ang_z = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
}

void		fdf_copy_in_cur(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->wdth * fdf->hght)
	{
		*(fdf->cur[i]) = *(fdf->pnt[i]);
		i++;
	}
}

void		fdf_set_coefficient(t_fdf *fdf)
{
	double kw;
	double kh;

	kw = (0.6 * WINSIZEX) / (fdf->wdth - 1);
	kh = (0.6 * WINSIZEY) / (fdf->hght - 1);
	fdf->k = (kw <= kh) ? kw : kh;
	fdf->kx = (int)((WINSIZEX - (fdf->wdth - 1) * fdf->k) / 2);
	fdf->ky = (int)((WINSIZEY - (fdf->hght - 1) * fdf->k) / 2);
	fdf->dx = (int)(((fdf->wdth - 1) * fdf->k) / 2);
	fdf->dy = (int)(((fdf->hght - 1) * fdf->k) / 2);
}

void		validate(char *buff, t_fdf *fdf, int nums)
{
	int len;
	int h;
	int w;
	int tmp;

	fdf->i = 0;
	h = 0;
	while (h < fdf->hght)
	{
		w = 0;
		while (w < fdf->wdth)
		{
			len = 0;
			if (buff[fdf->i] == '\n')
				fdf_error();
			tmp = fdf_atoi(&buff[fdf->i], &len);
			fdf->i += len;
			fdf->pnt[w + h * fdf->wdth]->x = w * fdf->k - fdf->dx;
			fdf->pnt[w + h * fdf->wdth]->y = h * fdf->k - fdf->dy;
			fdf->pnt[w + h * fdf->wdth]->z = tmp * 10;
			fdf->pnt[w + h * fdf->wdth]->color = fdf_color_peeks_deflt(tmp);
			w++;
		}
		while (buff[fdf->i] == ' ')
			fdf->i += 1;
		if (buff[fdf->i] != '\n')
			fdf_error();
		fdf->i += 1;
		h++;
	}
	return ;
}

void		fdf_malloc_fdf(char *buff, t_fdf *fdf)
{
	int i;

	i = 0;
	fdf->hght = count_enters(buff);
	fdf->wdth = read_first_line(buff);
	if ((fdf->pnt = (t_pnt **)ft_memalloc(sizeof(t_pnt *)
			* (fdf->hght * fdf->wdth))) == NULL)
		fdf_smthwrong();
	if ((fdf->cur = (t_pnt **)ft_memalloc(sizeof(t_pnt *)
			* (fdf->hght * fdf->wdth))) == NULL)
		fdf_smthwrong();
	while (i < fdf->hght * fdf->wdth)
	{
		if ((fdf->pnt[i] = (t_pnt *)ft_memalloc(sizeof(t_pnt))) == NULL)
			fdf_smthwrong();
		if ((fdf->cur[i] = (t_pnt *)ft_memalloc(sizeof(t_pnt))) == NULL)
			fdf_smthwrong();
		i++;
	}
	fdf_set_coefficient(fdf);
	validate(buff, fdf, fdf->wdth);
	return ;
}