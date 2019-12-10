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

void		set_coefficient(t_fdf *fdf)
{
	float kw;
	float kh;

	kw = (WINSIZE - WINSIZE / 2) / fdf->wdth;
	kh = (WINSIZE - WINSIZE / 2) / fdf->hght;
	fdf->k = (kw <= kh) ? kw : kh;
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
		//if (!( ft_isdigit(buff[i]) || buff[i] == '-' || buff[i] == '+'))
		//	fdf_notvalid();
		i++;
	}
	return (cnt);
}

void		validate(char *buff, t_fdf *fdf, int nums)
{
	int len;
	int h;
	int w;
	int tmp;

	fdf->i = 0;
	h = 0;
	set_coefficient(fdf);
	while (h < fdf->hght)
	{
		w = 0;
		while (w < fdf->wdth)
		{
			len = 0;
			if (buff[fdf->i] == '\n')
				fdf_error();
			tmp = fdf_atoi(&buff[fdf->i], &len);
			fdf->i += len;
			fdf->pnt[w + h * fdf->wdth]->x = w * fdf->k + WINSIZE / 4;
			fdf->pnt[w + h * fdf->wdth]->y = h * fdf->k + WINSIZE / 4;
			fdf->pnt[w + h * fdf->wdth]->z = tmp;
			fdf->pnt[w + h * fdf->wdth]->color = WINE;
			w++;
		}
		while (buff[fdf->i] == ' ')
			fdf->i += 1;
		if (buff[fdf->i] != '\n')
			fdf_error();
		fdf->i += 1;
		h++;
	}
	return ;
}

void		fdf_malloc_fdf(char *buff, t_fdf *fdf)
{
	int i;

	i = 0;
	fdf->hght = count_enters(buff);
	fdf->wdth = read_first_line(buff);
	if ((fdf->pnt = (t_pnt **)ft_memalloc(sizeof(t_pnt *)
			* (fdf->hght * fdf->wdth))) == NULL)
		fdf_smthwrong();
	while (i < fdf->hght * fdf->wdth)
	{
		if ((fdf->pnt[i] = (t_pnt *)ft_memalloc(sizeof(t_pnt))) == NULL)
			fdf_smthwrong();
		i++;
	}
	validate(buff, fdf, fdf->wdth);
	return ;
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
