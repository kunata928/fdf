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
	validate(buff, fdf, fdf->wdth);
	return ;
}