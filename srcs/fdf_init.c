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

void		fdf_init_subj(t_fdf *fdf, char *txt, char *buff)
{
	fdf->ang_x = 0;
	fdf->ang_y = 0;
	fdf->ang_z = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->h_peek = 1;
	fdf->condition.help = 0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINSIZEX, WINSIZEY, "Title");
	fdf->map_name = txt;
	fdf->hght = count_enters(buff);
	fdf->wdth = read_first_line(buff);
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

void validate(char *buff, t_fdf *fdf)
{
	int len;
	int tmp;
	int i;

	i = 0;
	while (buff[i] != '\n')
	{
		len = 0;
		if (buff[i] == '\n')
			fdf_error();
		tmp = fdf_atoi(&buff[i], &len);
		fdf->pnt[fdf->i]->x = (fdf->i % (fdf->wdth)) * fdf->k - fdf->dx;
		fdf->pnt[fdf->i]->y = (fdf->i / (fdf->wdth)) * fdf->k - fdf->dy;
		fdf->pnt[fdf->i]->z = tmp * Z_KOEFF;
		i += len;
		fdf->pnt[fdf->i]->color = fdf_set_color(&(buff[i]), &len, tmp);
		i += len;
		fdf->i += 1;
		while (buff[i] == ' ')
			i += 1;
		if (fdf->i % fdf->wdth == 0)
		{
			if (buff[i] != '\n')
				fdf_error();
			else
			{
				i++;
				if (fdf->i == fdf->wdth * fdf->hght
				&& buff[i] == '\0')
					return ;
				while (buff[i] == ' ')
					i += 1;
			}
		}
	}
}

void		fdf_malloc_fdf(char *buff, t_fdf *fdf, char *map_name)
{
	int i;

	i = 0;
	fdf_init_subj(fdf, map_name, buff);
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
	if ((fdf->curr = (t_curr *)ft_memalloc(sizeof(t_curr))) == NULL)
		return (fdf_smthwrong());
	fdf_set_coefficient(fdf);
	validate(buff, fdf);
	return ;
}

/*
 * void validate(char *buff, t_fdf *fdf)
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
			fdf->pnt[w + h * fdf->wdth]->z = tmp * Z_KOEFF;
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
}

void		fdf_malloc_fdf(char *buff, t_fdf *fdf, char *map_name)
{
	int i;

	i = 0;
	fdf_init_subj(fdf, map_name, buff);
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
	fdf->curr = (t_curr *)ft_memalloc(sizeof(t_curr));
	fdf_set_coefficient(fdf);
	validate(buff, fdf);
	return ;
}
 */
