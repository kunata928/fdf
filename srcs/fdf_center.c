/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_move_to_center(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->wdth * fdf->hght)
	{
		(fdf->cur[i])->x = (int)((fdf->cur[i])->x + fdf->shift_x);
		(fdf->cur[i])->y = (int)((fdf->cur[i])->y + fdf->shift_y);
		i++;
	}
	fdf->kx = fdf->kx + fdf->shift_x;
	fdf->ky = fdf->ky + fdf->shift_y;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf_plot(fdf);
	return ;
}

void		fdf_center(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->wdth * fdf->hght)
	{
		(fdf->cur[i])->x = (int)((fdf->cur[i])->x + fdf->kx + fdf->dx);
		(fdf->cur[i])->y = (int)((fdf->cur[i])->y + fdf->ky + fdf->dy);
		i++;
	}
	return ;
}
