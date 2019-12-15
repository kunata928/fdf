/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "../includes/fdf.h"

void		fdf_plot(t_fdf *fdf)
{
	int		i;

	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->img_ptr = mlx_new_image(fdf->mlx, WINSIZE, WINSIZE);
	fdf->image = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
			&fdf->s_line, &fdf->endian);
	i = 0;
	while (i++ < fdf->hght * fdf->wdth)
		if (i % (fdf->hght * fdf->wdth) != 0)
		{
			if (fdf->hght * fdf->wdth - i < fdf->wdth)
				print_line_br(*fdf, *(fdf->pnt[i]), *(fdf->pnt[i + 1]));
			else if (i % (fdf->wdth) == 0 && i != 0)
				print_line_br(*fdf, *(fdf->pnt[i]), *(fdf->pnt[i + 1]));
			else
			{
				print_line_br(*fdf, *(fdf->pnt[i]), *(fdf->pnt[i + 1]));
				print_line_br(*fdf, *(fdf->pnt[i]), *(fdf->pnt[i + 1]));
			}
		}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img_ptr);
}
