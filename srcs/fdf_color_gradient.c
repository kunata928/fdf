/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		percent(double start, double end, double curr)
{
	double placement;
	double distanse;

	placement = curr - start;
	distanse = end - start;
	return ((distanse == 0) ? 1.0 : (placement / distanse));
}

int			get_light(double start, double end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int			fdf_color(t_fdf fdf, int s, int e)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (fdf.curr->color == fdf.cur[e - 1]->color)
		return (fdf.curr->color);
	if (fdf.curr->dx > fdf.curr->dy)
		percentage = percent(fdf.cur[s - 1]->x, fdf.cur[e - 1]->x, fdf.curr->x);
	else
		percentage = percent(fdf.cur[s - 1]->y, fdf.cur[e - 1]->y, fdf.curr->y);
	red = get_light((fdf.cur[s - 1]->color >> 16) & 0xFF,
			(fdf.cur[e - 1]->color >> 16) & 0xFF, percentage);
	green = get_light((fdf.cur[s - 1]->color >> 8) & 0xFF,
			(fdf.cur[e - 1]->color >> 8) & 0xFF, percentage);
	blue = get_light(fdf.cur[s - 1]->color & 0xFF,
			fdf.cur[e - 1]->color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
