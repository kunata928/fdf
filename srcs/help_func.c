/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_help_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		skip_char(char *str, int *len, char ch)
{
	while (*(str + *len) && (*(str + *len) == ch))
		*len += 1;
}

int			norm_sign(char c)
{
	if (c && ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
			(c >= 'A' && c <= 'F')))
		return (1);
	else
		return (0);
}

double		distance(double x0, double y0, double x1, double y1)
{
	return (sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)));
}

void		swap(int *a, int *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}
