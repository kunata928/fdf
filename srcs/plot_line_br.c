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
	double c;

	c = *a;
	*a = *b;
	*b = c;
	c = *d;
	*d = *e;
	*e = c;
	return ;
}

void		ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
	return ;
}

void		fdf_br_init(t_fdf *fdf, int start, int end)
{
	fdf->br.xy0 = *((fdf->cur)[start - 1]);
	fdf->br.xy1 = *((fdf->cur)[end - 1]);
	fdf->br.color = fdf->br.xy0.color;
	fdf->br.col_start = fdf->br.xy0.color;
	fdf->br.col_end = fdf->br.xy1.color;
	if ((fdf->br.steep = fabs(fdf->br.xy1.y - fdf->br.xy0.y)
						 > fabs(fdf->br.xy1.x - fdf->br.xy0.x)))
		fdf_swap(&(fdf->br.xy0.x), &(fdf->br.xy0.y),
				 &(fdf->br.xy1.x), &(fdf->br.xy1.y));
	if (fdf->br.xy0.x > fdf->br.xy1.x)
	{
		fdf_swap(&(fdf->br.xy0.x), &(fdf->br.xy1.x),
				 &(fdf->br.xy0.y), &(fdf->br.xy1.y));
		ft_swap(&(fdf->br.col_start), &(fdf->br.col_end));
	}
	fdf->br.dx = fdf->br.xy1.x - fdf->br.xy0.x;
	fdf->br.dy = fabs(fdf->br.xy1.y - fdf->br.xy0.y);
	fdf->br.error = fdf->br.dx / 2;
	fdf->br.ystep = (fdf->br.xy0.y < fdf->br.xy1.y) ? 1 : -1;
	fdf->br.x = fdf->br.xy0.x;
	fdf->br.y = fdf->br.xy0.y;
	return ;
}

void		plot_line_br(t_fdf fdf, int start, int end)
{
	double e2;

	fdf_br_init(&fdf, start, end);
	while (fdf.br.x <= fdf.br.xy1.x)
	{
		fdf.tmp.x = fdf.br.steep ? fdf.br.y : fdf.br.x;
		fdf.tmp.y = fdf.br.steep ? fdf.br.x : fdf.br.y;
		if (fdf.tmp.x >= 0 && fdf.tmp.x < WINSIZEX
			&& fdf.tmp.y >= 0 && fdf.tmp.y < WINSIZEY)
			*(int*)(fdf.image + (int)(fdf.tmp.x) * 4 +
					(int)(fdf.tmp.y) * fdf.s_line)
					= color_pnt_deflt(fdf, fdf.br.x, start, end);
		fdf.br.error -= fdf.br.dy;
		e2 = fdf.br.error;
		if (fdf.br.error < 0)
		{
			fdf.br.y += fdf.br.ystep;
			fdf.br.error += fdf.br.dx;
		}
		(fdf.br.x) += 1;
	}
	return ;
}
//fdf_get_color(fdf, start, end);
//color_pnt_deflt(fdf, fdf.br.x, start, end);
