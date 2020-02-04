/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		ft_diff_double(double x0, double x1)
{
	double	d;

	d = x1 - x0;
	if (d < 0)
		return (-1 * d);
	return (d);
}

void		init_curr(t_fdf fdf, int start, int end)
{
	fdf.curr->x = P_START->x;
	fdf.curr->y = P_START->y;
	fdf.curr->dx = ft_diff_double(P_END->x, P_START->x);
	fdf.curr->dy = ft_diff_double(P_END->y, P_START->y);
	fdf.curr->color = P_START->color;//
	fdf.curr->sx = 1;
	fdf.curr->sy = 1;
	if (P_START->x > P_END->x)
		fdf.curr->sx = -1;
	if (P_START->y > P_END->y)
		fdf.curr->sy = -1;
	return ;
}

void		set_line(t_fdf fdf, int start, int end)
{
	double err;
	double e2;

	init_curr(fdf, start, end);
	err = -(fdf.curr->dy) / 2;
	if (fdf.curr->dx > fdf.curr->dy)
		err = fdf.curr->dx / 2;
	while (fdf.curr->x != P_END->x || fdf.curr->y != P_END->y)
	{
		if (fdf.curr->x >= 0 && fdf.curr->x < WINSIZEX
		&& fdf.curr->y >= 0 && fdf.curr->y < WINSIZEY)
			*(int*)(fdf.image + (int)fdf.curr->x * 4 +
					(int)fdf.curr->y * fdf.s_line) = fdf_color(fdf, start, end);
		e2 = err;
		if (e2 > -(fdf.curr->dx))
		{
			err -= fdf.curr->dy;
			fdf.curr->x += fdf.curr->sx;
		}
		if (e2 < fdf.curr->dy)
		{
			err += fdf.curr->dx;
			fdf.curr->y += fdf.curr->sy;
		}
	}
}
//color_pnt(fdf, start, end);
