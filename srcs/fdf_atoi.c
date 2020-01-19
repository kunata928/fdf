/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define MAX_LONG_LONG 9223372036854775807

double	fdf_doublebltoint(double nbr)
{
	double tmp;

	tmp = nbr;
	tmp -= (int)tmp;
	if (tmp >= 0.5)
		return((int)nbr + 1);
	else
		return ((int)nbr);
}

int		fdf_blank(char ch)
{
	if (ch == ' ' || ch == '\t'
		|| ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int		fdf_atoi(const char *str, int *len)
{
	unsigned long long		res;
	int						sign;

	res = 0;
	sign = 1;
	while (*(str + *len) && (fdf_blank(*(str + *len))))
		*len += 1;
	if (*(str + *len) == '\n')
		return (0);
	if (*(str + *len) == '-')
		sign = -1;
	if (*(str + *len) == '-' || *(str + *len) == '+')
		*len += 1;
	while (*(str + *len) && *(str + *len) >= '0' && *(str + *len) <= '9')
	{
		res = (unsigned long long)(res * 10 + (*(str + *len) - '0'));
		if (res > (long long)MAX_LONG_LONG && sign == 1)
			return (-1);
		if (res > (long long)MAX_LONG_LONG && sign == -1)
			return (0);
		*len += 1;
	}
	return (int)(res * sign);
}

int		fdf_atoi_hex(const char *str)
{
	int i;
	int num;

	if (!str || *(str) != '0' || *(str + 1) != 'x')
		return (-1);
	i = 2;
	while (!str[i] || (str[i] >= '0' && str[i] <= '9') ||
	(str[i] >= 'a' && str[i] <= 'f') ||
	(str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			num *= 16 + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			num *= 16 + str[i] - 'a' + 10;
		else
			num *= 16 + str[i] - 'A' + 10;
		i++;
	}
	return (num);
}