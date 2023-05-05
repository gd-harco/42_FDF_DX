/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:43:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_rotation(t_rot_info *rot)
{
	free(rot->x_rot_m);
	free(rot->y_rot_m);
	free(rot->z_rot_m);
	rot->x_rot_m = get_x_rotation_matrix(rot->rot_x);
	rot->y_rot_m = get_y_rotation_matrix(rot->rot_y);
	rot->z_rot_m = get_z_rotation_matrix(rot->rot_z);
}

void	update_translation(t_trans_info *trans)
{
	free(trans->m);
	trans->m = get_translation_matrix(trans);
}

void	change_projection(int key, t_fdf *fdf)
{
	if (key == XK_i && fdf->world->proj_type != ISO)
	{
		fdf->world->rot->rot_x = -120 * M_PI / 180.0f;
		fdf->world->rot->rot_y = 0.0f;
		fdf->world->rot->rot_z = 45 * M_PI / 180.0f;
		fdf->world->proj->current_m = fdf->world->proj->iso_m;
		fdf->world->proj_type = ISO;
	}
	else if (key == XK_p && fdf->world->proj_type != PERSP)
	{
		fdf->world->rot->rot_x = (-(M_PI / 4.0f));
		fdf->world->rot->rot_y = 0.0f;
		fdf->world->rot->rot_z = 0.0f;
		fdf->world->trans->translate_x = 0.0f;
		fdf->world->proj->current_m = fdf->world->proj->persp_m;
		fdf->world->proj_type = PERSP;
	}
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	update_rotation(fdf->world->rot);
	update_translation(fdf->world->trans);
	update_world(fdf->world);
	project_view(fdf);
	draw_all(fdf);
}

void	change_render_mode(t_fdf *fdf)
{
	if (fdf->world->render_type == LINE)
		fdf->world->render_type = POINT;
	else
		fdf->world->render_type = LINE;
	fdf->world->key_is_pressed = false;
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	draw_all(fdf);
}

void	change_cam_speed(int key, t_fdf *fdf)
{
	if (key == XK_F1)
	{
		if (fdf->cam_zoom_speed > 1)
			fdf->cam_zoom_speed -= 1;
	}
	else if (key == XK_F2)
	{
		if (fdf->cam_zoom_speed < 7)
			fdf->cam_zoom_speed += 1;
	}
	else if (key == XK_F5)
	{
		if (fdf->cam_trans_speed > 1)
			fdf->cam_trans_speed -= 1;
	}
	else if (key == XK_F6)
	{
		if (fdf->cam_trans_speed < 7)
			fdf->cam_trans_speed += 1;
	}
	fdf->world->key_is_pressed = false;
	fdf->world->key_pressed = 0;
}
