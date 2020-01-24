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
	while (i++ < fdf->hght * fdf->wdth - 1)
	{
			if (fdf->hght * fdf->wdth - i < fdf->wdth) // in case of last row
				plot_line_br(fdf, i, i + 1);
			else if (i  % (fdf->wdth) == 0 && i != 0) // in case of last col
				plot_line_br(fdf, i, i + fdf->wdth);
			else
			{
				plot_line_br(fdf, i, i + fdf->wdth);
				plot_line_br(fdf, i, i + 1);
			}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img_ptr);
	return;
}
