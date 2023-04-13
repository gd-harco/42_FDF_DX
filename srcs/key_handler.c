/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:19:02 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/12 19:33:17 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int	loop_hook(t_fdf *fdf_data)
{
	int	key;

	if (fdf_data->world->key_is_pressed)
	{
		key = fdf_data->world->key_pressed;
		if (key == XK_Escape || key == XK_q)
			exit_program(fdf_data);
		else if (key == XK_Left || key == XK_Right
			|| key == XK_Up || key == XK_Down)
			translation(key, fdf_data);
		else if (key == XK_a || key == XK_d || key == XK_w || key == XK_s)
			rotation(key, fdf_data);
		else if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4)
			change_fov(key, fdf_data);
		else if (key == XK_KP_Add || key == XK_KP_Subtract
			|| key == XK_equal || key == XK_minus)
			zoom(key, fdf_data);
	}
	return (0);
}

int	key_handler_in(int key, t_fdf *fdf_data)
{
	ft_printf("key_pressed\n");
	fdf_data->world->key_is_pressed = true;
	fdf_data->world->key_pressed = key;
	ft_printf("key_pressed = %d\n", fdf_data->world->key_pressed);
	return (0);
}

int	key_handler_out(int key, t_fdf *fdf_data)
{
	ft_printf("key_released\n");
	fdf_data->world->key_is_pressed = false;
	fdf_data->world->key_pressed -= key;
	ft_printf("key_pressed = %d\n", fdf_data->world->key_pressed);
	return (0);
}

void	rotation(int key, t_fdf *fdf_data)
{
	if (key == XK_w)
		fdf_data->world->rot->rot_x -= 0.01f;
	else if (key == XK_s)
		fdf_data->world->rot->rot_x += 0.01f;
	else if (key == XK_a)
		fdf_data->world->rot->rot_y -= 0.01f;
	else if (key == XK_d)
		fdf_data->world->rot->rot_y += 0.01f;
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_rotation(fdf_data->world->rot);
	update_world(fdf_data->world);
	project_view(fdf_data);
	draw_all(fdf_data);
}

void	zoom(int key, t_fdf *fdf_data)
{
	if (key == XK_KP_Add || key == XK_equal)
		fdf_data->world->trans->translate_z -= 0.05f;
	else if (key == XK_minus || key == XK_KP_Subtract)
		fdf_data->world->trans->translate_z += 0.05f;
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_translation(fdf_data->world->trans);
	update_world(fdf_data->world);
	project_view(fdf_data);
	draw_all(fdf_data);
}

void	translation(int key, t_fdf *fdf_data)
{
	if (key == XK_Up)
		fdf_data->world->trans->translate_y -= 0.05f;
	else if (key == XK_Down)
		fdf_data->world->trans->translate_y += 0.05f;
	else if (key == XK_Left)
		fdf_data->world->trans->translate_x -= 0.05f;
	else if (key == XK_Right)
		fdf_data->world->trans->translate_x += 0.05f;
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_translation(fdf_data->world->trans);
	update_world(fdf_data->world);
	project_view(fdf_data);
	draw_all(fdf_data);
}

void	change_fov(int key, t_fdf *fdf_data)
{
	if (key == XK_2)
		fdf_data->world->proj->fov = 90.0f;
	else if (key == XK_1)
		fdf_data->world->proj->fov = 60.0f;
	else if (key == XK_3)
		fdf_data->world->proj->fov = 120.0f;
	else if (key == XK_4)
		fdf_data->world->proj->fov = 150.0f;
	fdf_data->world->proj->fov_rad = 1.0f
		/ tanf(fdf_data->world->proj->fov * 0.5f / 180.0f * (float) M_PI);
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_projection(fdf_data->world->proj);
	project_view(fdf_data);
	draw_all(fdf_data);
}
