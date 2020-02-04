/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		color_pnt(t_fdf fdf, int start, int end)
{
	if (fdf.curr->color == P_END->color)
		return (fdf.curr->color);
	if (fdf.curr->x == P_START->x && fdf.curr->y == P_START->y)
		return (P_START->color);
	if (fdf.curr->x == P_END->x && fdf.curr->y == P_END->y)
		return (P_END->color);
	return (DEF_COL);
}

int		color_pnt_deflt(t_fdf fdf, int i, int i0, int i1)
{
	if (fdf.br.col_start == fdf.br.col_end)
		return (fdf.br.col_start);
	if (((fdf.cur)[i0 - 1]->x == fdf.tmp.x) &&
	((fdf.cur)[i0 - 1])->y == fdf.tmp.y)
		return ((fdf.cur)[i0 - 1]->color);
	if (((fdf.cur)[i1 - 1]->x == fdf.tmp.x) &&
		((fdf.cur)[i1 - 1])->y == fdf.tmp.y)
		return ((fdf.cur)[i1 - 1]->color);
	return (DEF_COL);
}

int		fdf_color_peeks_deflt(int tmp)
{
	if (tmp > 0)
		return (WHITE);
	if (tmp < 0)
		return (WINE);
	if (tmp == 0)
		return (ROSE);
}

