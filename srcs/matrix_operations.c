/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_rotate_x(double *y, double *z, double ang)
{
	double prev_y;
	double prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = fdf_doublebltoint(prev_y * cos(ang) + prev_z * sin(ang));
	*z = fdf_doublebltoint(-prev_y * sin(ang) + prev_z * cos(ang));
}

void	fdf_rotate_y(double *x, double *z, double ang)
{
	double prev_x;
	double prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = fdf_doublebltoint(prev_x * cos(ang) + prev_z * sin(ang));
	*z = fdf_doublebltoint(-prev_x * sin(ang) + prev_z * cos(ang));
}

void	fdf_rotate_z(double *x, double *y, double ang)
{
	double prev_x;
	double prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = fdf_doublebltoint(prev_x * cos(ang) - prev_y * sin(ang));
	*y = fdf_doublebltoint(prev_x * sin(ang) + prev_y * cos(ang));
}

void	fdf_eval_cur(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->wdth * fdf->hght)
	{
		fdf_rotate_x(&(fdf->cur[i]->y), &(fdf->cur[i]->z), fdf->ang_x);
		fdf_rotate_y(&(fdf->cur[i]->x), &(fdf->cur[i]->z), fdf->ang_y);
		fdf_rotate_z(&(fdf->cur[i]->x), &(fdf->cur[i]->y), fdf->ang_z);
		i++;
	}
}
