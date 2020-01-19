/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_check_key(int keycode)
{
	if (keycode == KEY_ESC || keycode == KEY_SPACE ||
			keycode == KEY_NUM_UP || keycode == KEY_NUM_DOWN)
		return (1);
	return (0);
}

void	fdf_key_press(int keycode, t_fdf *fdf)
{
	if (fdf_check_key(keycode))
	{

	}
}