/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_open(int argc, char **argv, int *fd)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf source_file.fdf");
		return (0);
	}
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int		fdf_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
