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

int		read_first_line(char *buff)
{
	int i;
	int c;
	int len;
	int tmp;

	c = 0;
	i = 0;
	while (buff[i] != '\n')
	{
		len = 0;
		tmp = fdf_atoi(&buff[i], &len);
		c++;
		i += len;
	}
	return (c + 1);
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
		//if (!( ft_isdigit(buff[i]) || buff[i] == '-' || buff[i] == '+'))
		//	fdf_notvalid();
		i++;
	}
	return (cnt);
}

void		validate(char *buff, t_fdf *fdf, int nums)
{
	int i;
	int len;
	int h;
	int w;

	i = 0;
	h = 0;
	while (buff[i])
	{
		w = 0;
		while (buff[i] != '\n')
		{
			len = 0;
			if (w > fdf->wdth)
				fdf_error();
			fdf->pnt[w + h * fdf->wdth]->x = w;
			fdf->pnt[w + h * fdf->wdth]->y = h;
			fdf->pnt[w + h * fdf->wdth]->z = fdf_atoi(&buff[i], &len);
			fdf->pnt[w + h * fdf->wdth]->color = WINE;
			i += len;
			w++;
		}
		i++;
		h++;
	}
	return ;
}

void		fdf_malloc_fdf(char *buff, t_fdf *fdf)
{
	int i;

	i = 0;
	if ((fdf->pnt = (t_fdf *)ft_memalloc(sizeof(t_fdf))) == NULL)
		fdf_smthwrong();
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
