/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_info_static0(t_fdf fdf)
{
	char *txt;

	mlx_string_put(fdf.mlx, fdf.win, 0, 0,
				   TEXT_COL0, fdf.map_name);
	mlx_string_put(fdf.mlx, fdf.win,
				   WINSIZEX - 150, 5, TEXT_COL1, "Shift dx:");
	txt = ft_itoa(-fdf.shift_x);
	mlx_string_put(fdf.mlx, fdf.win,
				   WINSIZEX - 57, 5, TEXT_COL2, txt);
	mlx_string_put(fdf.mlx, fdf.win,
				   WINSIZEX - 150, 23, TEXT_COL1, "Shift dy:");
	txt = ft_itoa(-fdf.shift_y);
	mlx_string_put(fdf.mlx, fdf.win,
				   WINSIZEX - 57, 23, TEXT_COL2, txt);
	free(txt);
	fdf_info_static1(fdf);
	fdf_info_help(fdf);
}

void		fdf_info_static1(t_fdf fdf)
{
	char *txt;

	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 150, 41, TEXT_COL1, "Angle Ox:");
	txt = ft_itoa((int)(fdf.ang_x * 180 / M_PI) % 360);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 57, 41, TEXT_COL2, txt);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 150, 59, TEXT_COL1, "Angle Oy:");
	txt = ft_itoa((int)(fdf.ang_y * 180 / M_PI) % 360);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 57, 59, TEXT_COL2, txt);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 150, 77, TEXT_COL1, "Angle Oz:");
	txt = ft_itoa((int)(fdf.ang_z * 180 / M_PI) % 360);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 57, 77, TEXT_COL2, txt);
	free(txt);
	//fdf_info_static1(fdf);
}

void		fdf_info_help(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win,
			5, WINSIZEX - 23, TEXT_COL0, "Press <H> for help");
	//if (fdf)
}