/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:43:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/18 18:18:35 by gd-harco         ###   ########lyon.fr   */
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

void	update_projection(t_proj_info *proj, t_fdf *fdf)
{
	free(proj->persp_m);
	proj->persp_m = get_persp_matrix(proj);
	if (fdf->world->proj_type == ISO)
		proj->current_m = proj->iso_m;
	else if (fdf->world->proj_type == PERSP)
		proj->current_m = proj->persp_m;
}

void	update_world(t_world_i *world)
{
	free(world->world_m);
	world->world_m = get_world_matrix(world);
}

void	update_image(t_fdf *fdf_data)
{
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	update_projection(fdf_data->world->proj, fdf_data);
	project_view(fdf_data);
	draw_all(fdf_data);
}
