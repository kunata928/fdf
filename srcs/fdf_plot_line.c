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

void		init_curr(t_fdf fdf, int s, int e)
{
	fdf.curr->x = fdf.cur[s - 1]->x;
	fdf.curr->y = fdf.cur[s - 1]->y;
	fdf.curr->dx = ft_diff_double(fdf.cur[e - 1]->x, fdf.cur[s - 1]->x);
	fdf.curr->dy = ft_diff_double(fdf.cur[e - 1]->y, fdf.cur[s - 1]->y);
	fdf.curr->color = fdf.cur[s - 1]->color;
	fdf.curr->sx = 1;
	fdf.curr->sy = 1;
	if (fdf.cur[s - 1]->x > fdf.cur[e - 1]->x)
		fdf.curr->sx = -1;
	if (fdf.cur[s - 1]->y > fdf.cur[e - 1]->y)
		fdf.curr->sy = -1;
	return ;
}

int			check_window(double x0, double y0)
{
	if (x0 < 0 || y0 < 0 || x0 >= WINSIZEX || y0 >= WINSIZEY)
		return (1);
	return (0);
}

void		change_points(t_fdf fdf, int *s, int *e)
{
	int start;

	start = *s;
	if (check_window(fdf.cur[start - 1]->x, fdf.cur[start - 1]->y))
		swap(s, e);
}

void		set_line(t_fdf fdf, int s, int e)
{
	double err;
	double e2;

	init_curr(fdf, s, e);
	err = -(fdf.curr->dy) / 2;
	if (fdf.curr->dx > fdf.curr->dy)
		err = fdf.curr->dx / 2;
	while (fdf.curr->x != fdf.cur[e - 1]->x || fdf.curr->y != fdf.cur[e - 1]->y)
	{
		if (fdf.curr->x >= 0 && fdf.curr->x < WINSIZEX
		&& fdf.curr->y >= 0 && fdf.curr->y < WINSIZEY)
			*(int*)(fdf.image + (int)fdf.curr->x * 4 +
					(int)fdf.curr->y * fdf.s_line) = fdf_color(fdf, s, e);
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
