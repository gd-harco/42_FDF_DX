/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:43:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 16:07:53 by gd-harco         ###   ########lyon.fr   */
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

void	change_projection(int key, t_fdf *fdf_data)
{
	if (key == XK_i)
	{
		fdf_data->world->rot->rot_x = -120 * M_PI / 180.0f;
		fdf_data->world->rot->rot_y = 0.0f;
		fdf_data->world->rot->rot_z = 45 * M_PI / 180.0f;
		fdf_data->world->proj->current_m = fdf_data->world->proj->iso_m;
		fdf_data->world->proj_type = ISO;
	}
	else if (key == XK_p)
	{
		fdf_data->world->rot->rot_x = (-(M_PI / 4.0f));
		fdf_data->world->rot->rot_y = 0.0f;
		fdf_data->world->rot->rot_z = 0.0f;
		fdf_data->world->trans->translate_x = 0.0f;
		fdf_data->world->proj->current_m = fdf_data->world->proj->persp_m;
		fdf_data->world->proj_type = PERSP;
	}
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_rotation(fdf_data->world->rot);
	update_translation(fdf_data->world->trans);
	update_world(fdf_data->world);
	project_view(fdf_data);
	draw_all(fdf_data);
}
