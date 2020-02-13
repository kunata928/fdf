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
	mlx_string_put(fdf.mlx, fdf.win, 0, 18,
				   TEXT_COL0, "Press <Esc> to exit");
	mlx_string_put(fdf.mlx, fdf.win,
				   WINSIZEX - 150, 5, TEXT_COL1, "Shift dx:");
	txt = ft_itoa(-fdf.shift_x);
	mlx_string_put(fdf.mlx, fdf.win,
				   WINSIZEX - 57, 5, TEXT_COL2, txt);
	mlx_string_put(fdf.mlx, fdf.win,
				   WINSIZEX - 150, 23, TEXT_COL1, "Shift dy:");
	free(txt);
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
	free(txt);
	txt = ft_itoa((int)(fdf.ang_y * 180 / M_PI) % 360);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 57, 59, TEXT_COL2, txt);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 150, 77, TEXT_COL1, "Angle Oz:");
	free(txt);
	txt = ft_itoa((int)(fdf.ang_z * 180 / M_PI) % 360);
	mlx_string_put(fdf.mlx, fdf.win,
			WINSIZEX - 57, 77, TEXT_COL2, txt);
	free(txt);
}

void		fdf_info_help(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win,
			5, WINSIZEY - 23, TEXT_COL0, "Press <h> for help");
	if (fdf.condition.help)
	{
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 18,
				TEXT_COL0, "Press    <4> or <6>     to rotate plato around Ox");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 36,
				TEXT_COL0, "Press    <2> or <8>     to rotate plato around Oy");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 54,
				TEXT_COL0, "Press    <1> or <3>     to rotate plato around Oz");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 77,
				TEXT_COL0, "Press <left> or <right> to move plato along Ox");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 95,
				TEXT_COL0, "Press   <up> or <down>  to move plato along Oy");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 95,
				TEXT_COL0, "Press   <up> or <down>  to move plato along Oy");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 118,
				TEXT_COL0, "Press   <i>   for isometry projection");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 136,
				TEXT_COL0, "Press   <t>   for    top   projection");
		mlx_string_put(fdf.mlx, fdf.win, 5, H_Y + 159,
				TEXT_COL0, "Press   <7> or <9>   for changing height ");
	}
}