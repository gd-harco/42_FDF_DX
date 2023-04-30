/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:19:02 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 13:16:53 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_fdf *fdf)
{
	int	key;

	if (fdf->world->key_is_pressed)
	{
		key = fdf->world->key_pressed;
		if (key == XK_p || key == XK_i)
			change_projection(key, fdf);
		if (key == XK_Escape || key == XK_q)
			exit_program(fdf);
		else if (key == XK_Left || key == XK_Right
			|| key == XK_Up || key == XK_Down)
			translate(key, fdf);
		else if (key == XK_a || key == XK_d || key == XK_w || key == XK_s)
			rotate(key, fdf);
		else if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4)
			change_fov(key, fdf);
		else if (key == XK_KP_Add || key == XK_KP_Subtract)
			zoom(key, fdf);
		else if (key == XK_equal || key == XK_minus)
			change_altitude(key, fdf);
		else if (key == XK_space)
			change_render_mode(fdf);
	}
	draw_ui(fdf->mlx_win->mlx, fdf->mlx_win->win_ptr);
	return (0);
}

int	key_handler_in(int key, t_fdf *fdf)
{
	fdf->world->key_is_pressed = true;
	fdf->world->key_pressed = key;
	return (0);
}

int	key_handler_out(int key, t_fdf *fdf)
{
	fdf->world->key_is_pressed = false;
	fdf->world->key_pressed -= key;
	return (0);
}
