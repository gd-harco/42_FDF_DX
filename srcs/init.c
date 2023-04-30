/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:38 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/27 17:47:38 by gd-harco         ###   ########lyon.fr   */
/*
                                                                      */
/* ************************************************************************** */

/**
 * @file init.c
 *
 * @brief FDF initialization file
 *
 * @author gd-harco
 * @date 2023-04-04
 */

#include "fdf.h"

static void	get_proj(t_fdf *fdf);
static void	get_world(t_fdf *fdf);
static void	init_translate(t_fdf *fdf);
static void	init_rotate(t_fdf *fdf);

void	sub_init(t_fdf *fdf)
{
	nlx_win_init(fdf_data->mlx_win, WIDTH, HEIGHT, "FDF");
	get_world(fdf_data);
	get_proj(fdf_data);
	fdf_data->img = malloc(sizeof(t_img) * 2);
	if (!fdf_data->img)
		exit_program(fdf_data);
	nlx_new_image(&fdf_data->img[RENDER],
		fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	nlx_new_image(&fdf_data->img[UI],
		fdf_data->mlx_win->mlx, WIDTH / 4, HEIGHT);
	fdf_data->tracker->t_img_loaded = true;
	get_cam_trans_speed(fdf_data);
	get_cam_rot_speed(fdf_data);
	get_cam_zoom_speed(fdf_data);
}

static void	get_proj(t_fdf *fdf)
{
	fdf->world->proj->aspect_ratio = (float)HEIGHT / (float)WIDTH;
	fdf->world->proj->fov = 90.0f;
	fdf->world->proj->z_near = 0.1f;
	fdf->world->proj->z_far = 1000.0f;
	fdf->world->proj->fov_rad = 1.0f
		/ tanf(fdf->world->proj->fov * 0.5f / 180.0f * (float)M_PI);
	fdf->world->proj->persp_m = get_persp_matrix(fdf->world->proj);
	if (WIDTH / fdf->map->width > HEIGHT / fdf->map->height)
		fdf->iso_factor = (float)HEIGHT / (float)fdf->map->height;
	else
		fdf->iso_factor = (float)WIDTH / (float)fdf->map->width;
	fdf->world->proj->iso_m = get_iso_matrix(fdf->iso_factor);
	if (fdf->world->proj_type == ISO)
		fdf->world->proj->current_m = fdf->world->proj->iso_m;
	else if (fdf->world->proj_type == PERSP)
		fdf->world->proj->current_m = fdf->world->proj->persp_m;
}

static void	get_world(t_fdf *fdf)
{
	fdf->world->key_is_pressed = false;
	fdf->world->key_pressed = 0;
	fdf->world->proj_type = ISO;
	fdf->world->render_type = LINE;
	fdf->world->trans = malloc(sizeof (t_trans_info));
	fdf->world->rot = malloc(sizeof (t_rot_info));
	fdf->world->proj = malloc(sizeof (t_proj_info));
	if (!fdf->world->trans || !fdf->world->rot
		|| !fdf->world->proj)
	{
		free(fdf->world->trans);
		free(fdf->world->rot);
		free(fdf->world->proj);
		free(fdf->world);
		fdf->tracker->t_world_loaded = false;
		exit_program(fdf);
	}
	init_translate(fdf);
	init_rotate(fdf);
	fdf->world->world_m = get_world_matrix(fdf->world);
	if (!fdf->world->world_m)
		exit_program(fdf);
}

static void	init_translate(t_fdf *fdf)
{
	if (fdf->map->width > fdf->map->height
		&& fdf->map->width > fdf->map->highest_point)
		fdf->world->trans->translate_z = fdf->map->width;
	else if (fdf->map->height > fdf->map->highest_point)
		fdf->world->trans->translate_z = fdf->map->height;
	else
		fdf->world->trans->translate_z = fdf->map->highest_point;
	fdf->world->trans->translate_x = 0.0f;
	fdf->world->trans->translate_y = 2.5f;
	fdf->world->trans->m = get_translation_matrix(fdf->world->trans);
}

static void	init_rotate(t_fdf *fdf)
{
	if (fdf->world->proj_type == PERSP)
	{
		fdf->world->rot->rot_x = - (M_PI / 4.0f);
		fdf->world->rot->rot_y = 0.0f;
		fdf->world->rot->rot_z = 0.0f;
	}
	else if (fdf->world->proj_type == ISO)
	{
		fdf->world->rot->rot_x = -120 * M_PI / 180.0f;
		fdf->world->rot->rot_y = 0.0f;
		fdf->world->rot->rot_z = 45 * M_PI / 180.0f;
	}
	fdf->world->rot->x_rot_m
		= get_x_rotation_matrix(fdf->world->rot->rot_x);
	fdf->world->rot->y_rot_m
		= get_y_rotation_matrix(fdf->world->rot->rot_y);
	fdf->world->rot->z_rot_m
		= get_z_rotation_matrix(fdf->world->rot->rot_z);
}
