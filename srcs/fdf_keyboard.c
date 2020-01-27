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
			keycode == KEY_NUM_UP || keycode == KEY_NUM_DOWN ||
			keycode == KEY_NUM_4 || keycode == KEY_NUM_6 ||
			keycode == KEY_NUM_2 || keycode == KEY_NUM_8 ||
			keycode == KEY_NUM_1 || keycode == KEY_NUM_3 ||
			keycode == KEY_NUM_UP || keycode == KEY_NUM_DOWN ||
			keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT ||
			keycode == KEY_SPACE)
		return (1);
	return (0);
}

int		fdf_key_press(int keycode, t_fdf *fdf)
{
	if (fdf_check_key(keycode))
	{
		if (keycode == KEY_ESC)
			exit(0);
		if (keycode == KEY_NUM_4 || keycode == KEY_NUM_6 || keycode == KEY_NUM_2
		|| keycode == KEY_NUM_8 || keycode == KEY_NUM_1 || keycode == KEY_NUM_3)
			fdf_rotate(keycode, fdf);
		else if (keycode == KEY_NUM_UP || keycode == KEY_NUM_DOWN ||
		keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT)
			fdf_shift(keycode, fdf);
		else if (keycode == KEY_SPACE)
			fdf_move_to_center(fdf);
	}
	return (0);
}
