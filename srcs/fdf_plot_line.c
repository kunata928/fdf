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

void		fdf_swap(double *a, double *b, double *d, double *e)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
	c = *d;
	*d = *e;
	*e = c;
	return ;
}

void		fdf_br_init(t_br *br, t_pnt xy0, t_pnt xy1)
{
	br->dx = xy1.x - xy0.x;
	br->dy = fabs(xy1.y - xy0.y);
	br->error = br->dx / 2;
	br->ystep = (xy0.y < xy1.y) ? 1 : -1;
	br->x = xy0.x;
	br->y = xy0.y;
	return ;
}

void			plot_line_br(t_fdf *fdf, int i0, int i1)
{
	t_br	*br;
	t_pnt	xy0;
	t_pnt	xy1;

	xy0 = *((fdf->cur)[i0 - 1]);
	xy1 = *((fdf->cur)[i1 - 1]);
	if (!(br = (t_br *)ft_memalloc(sizeof(t_br))))
		fdf_smthwrong();
	if ((br->dif = (xy1.y - xy0.y) > fabs(xy1.x - xy0.x)))
		fdf_swap(&(xy0.x), &(xy0.y), &(xy1.x), &(xy1.y));
	if (xy0.x > xy1.x)
		fdf_swap(&(xy0.x), &(xy1.x), &(xy0.y), &(xy1.y));
	fdf_br_init(br, xy0, xy1);
	while (br->x <= xy1.x)
	{
		fdf->tmp.x = br->dif ? br->y : br->x;
		fdf->tmp.y = br->dif ? br->x : br->y;
		*(int*)(fdf->image + (int)(fdf->tmp.x) * 4 +
				(int)(fdf->tmp.y) * fdf->s_line) = WHITE;
		br->error -= br->dy;
		if (br->error < 0)
		{
			br->y += br->ystep;
			br->error += br->dx;
		}
		(br->x) += 1;
	}
	ft_memdel((void **)&br);
	return ;
}
