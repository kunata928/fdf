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
