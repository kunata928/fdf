/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_error(void)
{
	ft_putstr("error");
	exit(1);
}

void		fdf_notvalid(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->pnt[fdf->i])
		ft_memdel((void **)&(fdf->pnt[(fdf->i)++]));
	fdf->i = 0;
	while (fdf->cur[fdf->i])
		ft_memdel((void **)&(fdf->cur[(fdf->i)++]));
	ft_memdel((void **)&fdf->pnt);
	ft_memdel((void **)&fdf->cur);
	ft_memdel((void **)&fdf);
	ft_putstr("not valid file");
	exit(1);
}

void		fdf_smthwrong(int n, t_fdf *fdf)
{
	fdf->i = 0;
	if (n == 0)
	{
		while (fdf->pnt[fdf->i])
			ft_memdel((void **)&(fdf->pnt[(fdf->i)++]));
		fdf->i = 0;
		while (fdf->cur[fdf->i])
			ft_memdel((void **)&(fdf->cur[(fdf->i)++]));
		ft_memdel((void **)&fdf->pnt);
		ft_memdel((void **)&fdf->cur);
	}
	else if (n == 2)
		ft_strdel(&fdf->lstr);
	else if (n == 4)
		ft_memdel((void **)&fdf->pnt);
	else if (n == 5)
	{
		ft_memdel((void **)&fdf->pnt);
		ft_memdel((void **)&fdf->cur);
	}
	ft_memdel((void **)&fdf);
	ft_putstr("smt went wrong");
	exit(1);
}

void		fdf_not_valid_col(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->pnt[fdf->i])
		ft_memdel((void **)&(fdf->pnt[(fdf->i)++]));
	fdf->i = 0;
	while (fdf->cur[fdf->i])
		ft_memdel((void **)&(fdf->cur[(fdf->i)++]));
	ft_memdel((void **)&fdf->pnt);
	ft_memdel((void **)&fdf->cur);
	ft_memdel((void **)&fdf);
	ft_putstr("not valid color, (Ex <0xAB271D or 0xfffff> followed after ',')");
	exit(1);
}
