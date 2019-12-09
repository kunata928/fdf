/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_net.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_0_row(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->hght - 1)
	{
		//print_line_br(fdf, fdf->pnt[i]->x, fdf->pnt[i]->y)
		i++;
	}
}

void		fdf_print_net(t_fdf *fdf)
{
	fdf->i = 0;
	fdf->w = 0;
	fdf->h = 0;
	while (fdf->h < fdf->hght - 1)
	{
		if (fdf->h == 0)
			print_0_row(fdf);


		fdf->h += 1;
	}
	return ;
}
