/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:05:02 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/29 15:09:30 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(int key, t_fdf *fdf_data)
{
	if (key == XK_Up)
		fdf_data->world->trans->translate_y -= fdf_data->cam_trans_speed;
	else if (key == XK_Down)
		fdf_data->world->trans->translate_y += fdf_data->cam_trans_speed;
	else if (key == XK_Left)
		fdf_data->world->trans->translate_x -= fdf_data->cam_trans_speed;
	else if (key == XK_Right)
		fdf_data->world->trans->translate_x += fdf_data->cam_trans_speed;
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img[RENDER].img_ptr);
	nlx_new_image(&fdf_data->img[RENDER], fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_translation(fdf_data->world->trans);
	update_world(fdf_data->world);
	project_view(fdf_data);
	draw_all(fdf_data);
}

void	rotate(int key, t_fdf *fdf_data)
{
	if (key == XK_w)
		fdf_data->world->rot->rot_x -= fdf_data->cam_rot_speed;
	else if (key == XK_s)
		fdf_data->world->rot->rot_x += fdf_data->cam_rot_speed;
	else if (key == XK_a)
		fdf_data->world->rot->rot_y -= fdf_data->cam_rot_speed;
	else if (key == XK_d)
		fdf_data->world->rot->rot_y += fdf_data->cam_rot_speed;
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img[RENDER].img_ptr);
	nlx_new_image(&fdf_data->img[RENDER], fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_rotation(fdf_data->world->rot);
	update_world(fdf_data->world);
	project_view(fdf_data);
	draw_all(fdf_data);
}

void	zoom(int key, t_fdf *fdf_data)
{
	if (fdf_data->world->proj_type == ISO)
	{
		if (key == XK_KP_Add)
			fdf_data->iso_factor += fdf_data->cam_zoom_speed;
		else if (key == XK_KP_Subtract)
			fdf_data->iso_factor -= fdf_data->cam_zoom_speed;
		free(fdf_data->world->proj->iso_m);
		fdf_data->world->proj->iso_m = get_iso_matrix(fdf_data->iso_factor);
		fdf_data->world->proj->current_m = fdf_data->world->proj->iso_m;
	}
	else if (fdf_data->world->proj_type == PERSP)
	{
		if (key == XK_KP_Add)
			fdf_data->world->trans->translate_z -= fdf_data->cam_zoom_speed;
		else if (key == XK_KP_Subtract)
			fdf_data->world->trans->translate_z += fdf_data->cam_zoom_speed;
	}
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img[RENDER].img_ptr);
	nlx_new_image(&fdf_data->img[RENDER], fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_translation(fdf_data->world->trans);
	update_world(fdf_data->world);
	project_view(fdf_data);
	draw_all(fdf_data);
}
