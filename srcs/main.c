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
	t_pnt		*xy_0;
	t_pnt		*xy_n;
	t_fdf		*fdf;
	int			i;

	i = 0;
	xy_0 = (t_pnt *)ft_memalloc(sizeof(t_pnt));
	xy_n = (t_pnt *)ft_memalloc(sizeof(t_pnt));
	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	xy_0->x = 100;
	xy_0->y = 500;
	xy_n->x = 500;
	xy_n->y = 600;
	xy_0->color = WINE;
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, WINSIZE, WINSIZE, "Title");
	//print_line_br(mlx, win, *xy_0, *xy_n);
	fdf_read_file("/Users/pmelodi/Projects/fdf0/test_maps/elem.fdf", fdf);
	while (i < fdf->wdth * fdf->hght + 1)
	{
		ft_putnbr((fdf->pnt)[i]->z);
		ft_putchar(' ');
		i++;
	}
	//mlx_loop(mlx);
	return (0);
	free(fdf);
}