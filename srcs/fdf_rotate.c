/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_rotate(int keycode, t_fdf *fdf)
{
	int i;

	i = 0;
	if (keycode == KEY_NUM_4)
		fdf->ang_x -= ANG_STEP;
	else if (keycode == KEY_NUM_6)
		fdf->ang_x += ANG_STEP;
	else if (keycode == KEY_NUM_2)
		fdf->ang_y -= ANG_STEP;
	else if (keycode == KEY_NUM_8)
		fdf->ang_y += ANG_STEP;
	else if (keycode == KEY_NUM_1)
		fdf->ang_z -= ANG_STEP;
	else if (keycode == KEY_NUM_3)
		fdf->ang_z += ANG_STEP;
	fdf_copy_in_cur(fdf);
	while (i < fdf->hght * fdf->wdth)
	{
		ft_putnbr((fdf->pnt)[i]->x);
		ft_putchar(' ');
		ft_putnbr((fdf->pnt)[i]->y);
		ft_putchar(';');
		i++;
		if (i % fdf->wdth == 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
	i = 0;
	while (i < fdf->hght * fdf->wdth)
	{
		ft_putnbr((fdf->cur)[i]->x);
		ft_putchar(' ');
		ft_putnbr((fdf->cur)[i]->y);
		ft_putchar(';');
		i++;
		if (i % fdf->wdth == 0)
			ft_putchar('\n');
	}
	fdf_eval_cur(fdf);
	ft_putchar('\n');
	i = 0;
	while (i < fdf->hght * fdf->wdth)
	{
		ft_putnbr((fdf->cur)[i]->x);
		ft_putchar(' ');
		ft_putnbr((fdf->cur)[i]->y);
		ft_putchar(';');
		i++;
		if (i % fdf->wdth == 0)
			ft_putchar('\n');
	}
	ft_putchar(';');
	ft_putchar('\n');
	fdf_plot(fdf);
}
