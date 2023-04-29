/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:19:02 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/29 17:19:30 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_fdf *fdf_data)
{
	int	key;

	if (fdf_data->world->key_is_pressed)
	{
		key = fdf_data->world->key_pressed;
		if (key == XK_p || key == XK_i)
			change_projection(key, fdf_data);
		if (key == XK_Escape || key == XK_q)
			exit_program(fdf_data);
		else if (key == XK_Left || key == XK_Right
			|| key == XK_Up || key == XK_Down)
			translate(key, fdf_data);
		else if (key == XK_a || key == XK_d || key == XK_w || key == XK_s)
			rotate(key, fdf_data);
		else if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4)
			change_fov(key, fdf_data);
		else if (key == XK_KP_Add || key == XK_KP_Subtract)
			zoom(key, fdf_data);
		else if (key == XK_equal || key == XK_minus)
			change_altitude(key, fdf_data);
		else if (key == XK_space)
			change_render_mode(fdf_data);
	}
	draw_ui(fdf_data);
	return (0);
}

int	key_handler_in(int key, t_fdf *fdf_data)
{
	fdf_data->world->key_is_pressed = true;
	fdf_data->world->key_pressed = key;
	return (0);
}

int	key_handler_out(int key, t_fdf *fdf_data)
{
	fdf_data->world->key_is_pressed = false;
	fdf_data->world->key_pressed -= key;
	return (0);
}
