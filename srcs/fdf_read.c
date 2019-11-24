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
#define MAX_LONG_LONG 9223372036854775807

static void	fdf_error()
{
	ft_putstr("error");
	exit ;
}

static int	fdf_blank(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t'
		|| ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

static int	fdf_atoi(const char *str, int *len)
{
	unsigned long long		res;
	int						sign;

	res = 0;
	sign = 1;
	while (*(str + *len) && (fdf_blank(*(str + *len))))
		*len += 1;
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

int		read_first_line(char *buff)
{
	int i;
	int cnt;
	int len;
	int tmp;

	cnt = 0;
	i = 0;
	while (buff[i] != '\n')
	{
		len = 0;
		tmp = fdf_atoi(&buff[i], &len);
		cnt++;
		i += len;
	}
}

int		count_enters(char *buff)
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

static void		validate(char *buff, t_o ***fdf, int nums)
{
	int x;
	int y;
	int i;
	int cnt;
	int len;
	int tmp;

	cnt = 0;
	i = 0;
	while (buff[x] != '\0')
	{
		y = 0;
		while (buff[y] != '\n')
		{
			len = 0;
			fdf[x][y]->z = fdf_atoi(&buff[i], &len);
			cnt++;
			i += len;
			y++;
		}
		i++;
	}
}

static void		fdf_malloc_fdf(char *buff, t_o ***fdf)
{
	t_val	val;
	int i;

	i = 0;
	val.n = count_enters(buff);
	val.nums = read_first_line(buff);
	fdf = (t_o ***)ft_memalloc(sizeof(t_o **) * (val.n + 1));
	fdf[val.n + 1] = NULL;
	while (i < val.n)
	{
		fdf[i] = (t_o **)ft_memalloc(sizeof(t_o *) * (val.nums + 1));
		fdf[i][val.nums + 1] = NULL;
	}
	validate(buff, fdf, val.nums);
}

int			fdf_read_file(char *txt, t_o ***fdf)
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
}
