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
	if (c && ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
	(c >= 'A' && c <= 'F')))
		return (1);
	else
		return (0);
}

void		fdf_count_numbers(char *str, int *len)
{
	skip_char(str, len, ' ');
	if (*(str + *len) == '-' || *(str + *len) == '+')
		*len += 1;
	while (*(str + *len) && *(str + *len) >= '0' && *(str + *len) <= '9')
		*len += 1;
	if (*(str + *len) && *(str + *len) == ',')
	{
		*len += 1;
		if (*(str + *len) && *(str + *len + 1)
		&& *(str + *len) == '0' && *(str + *len + 1) == 'x')
		{
			*len += 2;
			while (norm_sign(*(str + *len)))
				*len += 1;
		}
		else
			fdf_not_valid_col();
	}
	if (*(str + *len) != ' ' && *(str + *len) != '\n')
		fdf_notvalid();
	skip_char(str, len, ' ');
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

int			fdf_read_file(int fd, t_fdf *fdf, char *map_name)
{
	int		len;
	int		longlen;
	char	buff[BUFF + 1];
	char	*longstr;
	char	*buff1;


	len = read(fd, buff, BUFF);
	if (!len)
		fdf_error();
	if ((longstr = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		fdf_error();
	longlen = len;
	while (len != 0)
	{
		len = read(fd, buff, BUFF);
		if (len < 0)
			fdf_error();
		if (len)
		{
			if ((buff1 = (char *)malloc((longlen + len + 1) * sizeof(char))) == NULL)
				fdf_error();
			ft_memcpy(buff1, longstr, longlen);
			ft_memcpy(&(buff1[longlen]), buff, len);
			longlen += len;
			free(longstr);
			longstr = buff1;
		}
	}
	if (buff[len - 1] != '\n')
	{
		buff[len] = '\n';
		buff[len + 1] = '\0';
	}
	else
		buff[len] = '\0';
	fdf_malloc_fdf(buff, fdf, map_name);
	return (1);
}

//int		len;
//	int		longlen;
//	char	buff[BUFF + 1];
//	char	*longstr;
//	char	*buff1;
//
//
//	len = read(fd, buff, BUFF);
//	if (!len)
//		fdf_error();
//	if ((longstr = (char *)malloc((len + 1) * sizeof(char))) == NULL)
//		fdf_error();
//	longlen = len;
//	while (len != 0)
//	{
//		len = read(fd, buff, BUFF);
//		if (len < 0)
//			fdf_error();
//		if (len)
//		{
//			if ((buff1 = (char *)malloc((longlen + len + 1) * sizeof(char))) == NULL)
//				fdf_error();
//			ft_memcpy(buff1, longstr, longlen);
//			ft_memcpy(&(buff1[longlen]), buff, len);
//			longlen += len;
//			free(longstr);
//			longstr = buff1;
//		}
//	}
//	if (buff[len - 1] != '\n')
//	{
//		buff[len] = '\n';
//		buff[len + 1] = '\0';
//	}
//	else
//		buff[len] = '\0';
//	fdf_malloc_fdf(buff, fdf, map_name);
//	return (1);