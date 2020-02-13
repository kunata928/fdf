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

int main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	//if (!(fdf_open(argc, argv, &fd)))
	//	return (0);

	fd = open("/Users/pmelodi/Projects/fdf0/test_maps/elem.fdf", O_RDONLY);
	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (!(fdf_read_file(fd, fdf,
			"/Users/pmelodi/Projects/fdf0/test_maps/elem.fdf"))) //argv[1]
		return (0);
	//the matrix read correctly
	fdf_copy_in_cur(fdf);
	fdf_center(fdf);
	fdf_plot(fdf);
	mlx_hook(fdf->win, 2, 0, fdf_key_press, fdf);
	mlx_loop(fdf->mlx);
	return (0);
	//free(fdf);
}
//mlx_clear_window(fdf->mlx, fdf->win);
//fdf->img_ptr = mlx_new_image(fdf->mlx, WINSIZEX, WINSIZEY);
//fdf->image = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
//							   &fdf->s_line, &fdf->endian);
//set_line(*fdf, 1, 2);
//	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_ptr, 0, 0);
//	mlx_destroy_image(fdf->mlx, fdf->img_ptr);
