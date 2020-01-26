/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_center(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->wdth * fdf->hght)
	{
		(fdf->cur[i])->x = (int)((fdf->cur[i])->x + fdf->kx + fdf->dx);
		(fdf->cur[i])->y = (int)((fdf->cur[i])->y + fdf->ky + fdf->dy);
		i++;
	}
	return ;
}