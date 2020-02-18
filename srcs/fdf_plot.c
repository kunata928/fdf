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

#include "../includes/fdf.h"

void		fdf_copy_in_cur(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->wdth * fdf->hght)
	{
		*(fdf->cur[i]) = *(fdf->pnt[i]);
		i++;
	}
}

void		fdf_plot1pxl(t_fdf *fdf)
{
	fdf->cur[0]->x = fdf->kx - fdf->shift_x;
	fdf->cur[0]->y = fdf->ky - fdf->shift_y;
	if (fdf->cur[0]->x < WINSIZEX && fdf->cur[0]->y < WINSIZEY)
		*(int*)(fdf->image + (int)(fdf->cur[0]->x) * 4 +
			(int)(fdf->cur[0]->y) * fdf->s_line) = fdf->pnt[0]->color;
	if (fdf->cur[0]->x > W_XS && fdf->cur[0]->x < W_XS + 50 &&
			fdf->cur[0]->y > W_YS && fdf->cur[0]->y < W_YS + 50)
		fdf->condition.special = 1;
}

void		fdf_info1pxl(t_fdf *fdf)
{
	if ((fdf->hght - 1 == 0) && (fdf->wdth - 1 == 0))
	{
		mlx_string_put(fdf->mlx, fdf->win, WINSIZEX / 3.3, WINSIZEY / 4,
					TEXT_COL0, "You are really smart and want to see only "
								"one pixel ha ha ha");
		mlx_string_put(fdf->mlx, fdf->win, WINSIZEX / 3.5, WINSIZEY / 1.4,
					TEXT_COL0, "Buuuuut, you can try to find unusual zone "
								"and see my secret message");
		if (fdf->condition.special)
			mlx_string_put(fdf->mlx, fdf->win, WINSIZEX / 2.5, WINSIZEY / 2,
					ROSE, "Pmelodi loves you, dear peer <3");
	}
}

void		fdf_plot(t_fdf *fdf)
{
	int i;

	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->img_ptr = mlx_new_image(fdf->mlx, WINSIZEX, WINSIZEY);
	fdf->image = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
			&fdf->s_line, &fdf->endian);
	i = 0;
	if ((fdf->hght - 1 == 0) && (fdf->wdth - 1 == 0))
		fdf_plot1pxl(fdf);
	while (i++ < fdf->hght * fdf->wdth - 1)
	{
		if (fdf->hght * fdf->wdth - i < fdf->wdth)
			set_line(*fdf, i, i + 1);
		else if (i % (fdf->wdth) == 0 && i != 0)
			set_line(*fdf, i, i + fdf->wdth);
		else
		{
			set_line(*fdf, i, i + fdf->wdth);
			set_line(*fdf, i, i + 1);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img_ptr);
	fdf_info_static0(*fdf);
	fdf_info1pxl(fdf);
}
