/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		color_pnt(t_fdf fdf, int s, int e)
{
	if (fdf.curr->color == fdf.cur[e - 1]->color)
		return (fdf.curr->color);
	if (fdf.curr->x == fdf.cur[s - 1]->x && fdf.curr->y == fdf.cur[s - 1]->y)
		return (fdf.cur[s - 1]->color);
	if (fdf.curr->x == fdf.cur[e - 1]->x && fdf.curr->y == fdf.cur[e - 1]->y)
		return (fdf.cur[e - 1]->color);
	return (DEF_COL);
}

int		fdf_color_peeks_deflt(int tmp)
{
	if (tmp > 0)
		return (WHITE);
	if (tmp < 0)
		return (WINE);
	return (ROSE);
}

int		fdf_def_col(int z)
{
	if (z == 0)
		return (ROSE);
	if (z > 0 && z <= 3)
		return (R_1);
	if (z > 3 && z <= 6)
		return (R_2);
	if (z > 6 && z <= 8)
		return (R_3);
	if (z > 8 && z <= 10)
		return (R_4);
	if (z > 10 && z <= 20)
		return (R_5);
	if (z > 20)
		return (WHITE);
	return (DARK_R);
}

int		fdf_set_color(char *buff, int *len, int z, t_fdf *fdf)
{
	int i;

	i = 0;
	if (buff[i] && (buff[i] == ' ' || buff[i] == '\n'))
	{
		if (buff[i] == ' ')
			*len = 1;
		else
			*len = 0;
		return (fdf_def_col(z));
	}
	if (buff[i] == ',')
		return (fdf_atoi_hex(&(buff[i + 1]), len, fdf));
	fdf_error();
	return (0);
}
