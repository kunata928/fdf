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

int main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	if (!(fdf_open(argc,  argv, &fd)))
		return (0);
	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (!(fdf_read_file(fd, fdf, argv[1])))
		return (0);
	fdf_copy_in_cur(fdf);
	fdf_center(fdf);
	fdf_plot(fdf);
	mlx_hook(fdf->win, 2, 0, fdf_key_press, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
