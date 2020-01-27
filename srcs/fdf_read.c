/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			norm_sign(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '\n' || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

void		fdf_count_numbers(char *str, int *len)
{
	while (*(str + *len) && (*(str + *len) == ' '))
		*len += 1;
	if (*(str + *len) == '-' || *(str + *len) == '+')
		*len += 1;
	while (*(str + *len) && *(str + *len) >= '0' && *(str + *len) <= '9')
		*len += 1;
	while (*(str + *len) && (*(str + *len) == ' '))
		*len += 1;
}

int			read_first_line(char *buff)
{
	int i;
	int c;
	int len;

	c = 0;
	i = 0;
	while (buff[i] != '\n')
	{
		len = 0;
		if (!(norm_sign(buff[i])))
			fdf_error();
		fdf_count_numbers(&buff[i], &len);
		i += len;
		c++;
	}
	return (c);
}

int			count_enters(char *buff)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}

int			fdf_read_file(char *txt, t_fdf *fdf)
{
	int		fd;
	int		len;
	char	buff[BUFF + 2];

	if ((fd = open(txt, O_RDONLY)) < 0)
		fdf_error();
	if (!(len = read(fd, buff, BUFF)))
		fdf_error();
	if (buff[len - 1] != '\n')
	{
		buff[len] = '\n';
		buff[len + 1] = '\0';
	}
	else
		buff[len] = '\0';
	fdf_malloc_fdf(buff, fdf);
	return (1);
}
