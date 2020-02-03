/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int main(void)
{
	t_fdf		*fdf;
	int			i;
	t_pnt xy0;
	t_pnt xy1;

	i = 0;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINSIZEX, WINSIZEY, "Title");

	fdf_read_file("/Users/pmelodi/Projects/fdf0/test_maps/elem.fdf", fdf);
	//the matrix read correctly
	//plot_line_br_1(fdf->mlx, fdf->win, 450, 624, 450, 499);
	fdf_copy_in_cur(fdf);
	fdf_center(fdf);
	fdf_plot(fdf);
	mlx_hook(fdf->win, 2, 0, fdf_key_press, fdf);

	mlx_loop(fdf->mlx);
	return (0);
	//free(fdf);
}
