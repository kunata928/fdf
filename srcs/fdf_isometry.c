/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_plot_isometry(t_fdf *fdf)
{
	fdf->ang_x = 0.785398;
	fdf->ang_y = 0.610865;
	fdf->ang_z = 0.523599;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->k = 1.2;
	fdf_copy_in_cur(fdf);
	fdf_eval_cur(fdf);
	fdf_center(fdf);
	fdf_plot(fdf);
}

void		fdf_plot_top_view(t_fdf *fdf)
{
	fdf->ang_x = 0;
	fdf->ang_y = 0;
	fdf->ang_z = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->k = 1;
	fdf_copy_in_cur(fdf);
	fdf_eval_cur(fdf);
	fdf_center(fdf);
	fdf_plot(fdf);
}

void		fdf_plot_front_view(t_fdf *fdf)
{
	fdf->ang_x = -M_PI / 2;
	fdf->ang_y = 0;
	fdf->ang_z = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	//fdf->scale = 1;
	fdf_copy_in_cur(fdf);
	fdf_eval_cur(fdf);
	fdf_center(fdf);
	fdf_plot(fdf);
}

void		fdf_change_height(t_fdf *fdf, int key)
{
	int i;
	int h_peek;

	i = 0;
	h_peek = 0;
	if (key == KEY_NUM_7)
		h_peek -= DZ;
	else
		h_peek += DZ;
	fdf_copy_in_cur(fdf);
	while (i < fdf->wdth * fdf->hght)
	{
		if (((fdf->pnt[i])->z != 0))
		{
			if (((fdf->pnt[i])->z + fdf->h_peek + h_peek >= 0))
			{
				(fdf->cur[i])->z = (fdf->cur[i])->z + h_peek + fdf->h_peek;
			}
			else
			{
				(fdf->cur[i])->z = 0;
				h_peek = 0;
			}
		}
		i++;
	}
	fdf->h_peek += h_peek;
	fdf_eval_cur(fdf);
	fdf_center(fdf);
	fdf_plot(fdf);
}
