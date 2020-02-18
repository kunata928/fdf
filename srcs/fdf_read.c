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

void		fdf_count_numbers(char *str, int *len, t_fdf *fdf)
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
			fdf_not_valid_col(fdf);
	}
	if (*(str + *len) != ' ' && *(str + *len) != '\n')
		fdf_notvalid(fdf);
	skip_char(str, len, ' ');
}

int			read_first_line(char *buff, t_fdf *fdf)
{
	int i;
	int c;
	int len;

	c = 0;
	i = 0;
	while (buff[i] != '\n')
	{
		len = 0;
		fdf_count_numbers(&buff[i], &len, fdf);
		i += len;
		c++;
	}
	return (c);
}

int			count_enters(char *buff, t_fdf *fdf)
{
	int i;
	int cnt;
	int flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (buff[i])
	{
		if (cnt == 0 && (buff[i] >= '0' && buff[i] <= '9'))
			flag = 1;
		if (buff[i] == '\n')
			cnt++;
		i++;
	}
	if (!flag)
		fdf_notvalid(fdf);
	return (cnt);
}

int			fdf_read_file(int fd, t_fdf *fdf, char *map_name)
{
	int		llen;
	char	buff[BUFF + 1];
	char	*tmp_buff;

	fdf->len = read(fd, buff, BUFF);
	if (!(fdf->len))
		fdf_error();
	if ((fdf->lstr = (char *)ft_memalloc((1) * sizeof(char))) == NULL)
		fdf_smthwrong(1, fdf);
	llen = 0;
	while (fdf->len != 0)
	{
		if ((tmp_buff = (char *)ft_memalloc(llen + fdf->len + 1)) == NULL)
			fdf_smthwrong(2, fdf);
		ft_memcpy(tmp_buff, fdf->lstr, llen);
		ft_memcpy(&(tmp_buff[llen]), buff, fdf->len);
		llen += fdf->len;
		free(fdf->lstr);
		fdf->lstr = tmp_buff;
		fdf->len = read(fd, buff, BUFF);
	}
	close(fd);
	fdf_malloc_fdf(fdf->lstr, fdf, map_name, llen);
	return (1);
}
