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
	void	*window;
	int		bool;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");
	//mlx_pixel_put(mlx, window, 100, 100, 0xFFFFFF );
	mlx_string_put(mlx, window, 100, 100, WHITE, "her");
	mlx_loop(mlx);
	return (0);
}