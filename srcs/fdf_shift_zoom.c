/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shift_zoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_add_shift(t_fdf *fdf, int flag, int dx, int dy)
{
	int i;

	i = 0;
	while (i < fdf->wdth * fdf->hght)
	{
		if (flag)
			(fdf->cur[i])->x = (int)((fdf->cur[i])->x + dx);
		else
			(fdf->cur[i])->y = (int)((fdf->cur[i])->y + dy);
		i++;
	}
	return ;
}

void		fdf_shift(int key, t_fdf *fdf)
{
	int dx;
	int dy;

	dx = 0;
	dy = 0;
	if (key == KEY_NUM_LEFT)
		dx -= SHIFT_STEP;
	else if (key == KEY_NUM_RIGHT)
		dx += SHIFT_STEP;
	else if (key == KEY_NUM_DOWN)
		dy += SHIFT_STEP;
	else if (key == KEY_NUM_UP)
		dy -= SHIFT_STEP;
	if (key == KEY_NUM_LEFT || key == KEY_NUM_RIGHT)
		fdf_add_shift(fdf, 1, dx, dy);
	if (key == KEY_NUM_DOWN || key == KEY_NUM_UP)
		fdf_add_shift(fdf, 0, dx, dy);
	fdf_plot(fdf);
	fdf->kx += dx;
	fdf->ky += dy;
	fdf->shift_x -= dx;
	fdf->shift_y -= dy;
}
