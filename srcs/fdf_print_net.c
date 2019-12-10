/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_net.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "../includes/fdf.h"

void		print_0(t_fdf *fdf)
{
	int i;

	i = 1;
	while (i < fdf->wdth)
	{
		print_line_br(fdf, *(fdf->pnt[i - 1]), *(fdf->pnt[i]));
		i++;
	}
	i = 1;
	while (i < fdf->hght)
	{
		print_line_br(fdf, *(fdf->pnt[(i-1) * fdf->wdth]),
				*(fdf->pnt[i * fdf->wdth]));
		i++;
	}
	return ;
}

void		fdf_print_net(t_fdf *fdf)
{
	fdf->h = 1;
	print_0(fdf);
	while (fdf->h < fdf->hght)
	{
		fdf->w = 1;
		while (fdf->w < fdf->wdth)
		{
			print_line_br(fdf, *(fdf->pnt[(fdf->h - 1) * fdf->wdth + fdf->w]),
					*(fdf->pnt[fdf->h * fdf->wdth + fdf->w]));
			print_line_br(fdf, *(fdf->pnt[fdf->h * fdf->wdth + fdf->w - 1]),
					*(fdf->pnt[fdf->h * fdf->wdth + fdf->w]));
			fdf->w += 1;
		}
		fdf->h += 1;
	}
	return ;
}
