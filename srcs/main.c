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

int main(void)
{
	void	*mlx;
	void	*win;
	int		bool;
	t_xy	*xy_0;
	t_xy	*xy_n;

	xy_0 = (t_xy *)ft_memalloc(sizeof(t_xy));
	xy_n = (t_xy *)ft_memalloc(sizeof(t_xy));
	xy_0->x = 100;
	xy_0->y = 500;
	xy_n->x = 500;
	xy_n->y = 200;
	xy_0->color = WINE;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WINSIZE, WINSIZE, "Title");
	print_line_br(mlx, win, *xy_0, *xy_n);
	mlx_loop(mlx);
	return (0);
}