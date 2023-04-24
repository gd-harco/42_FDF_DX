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

static void	get_proj(t_fdf *fdf_data);
static void	get_world(t_fdf *fdf_data);
static void	init_translate(t_fdf *fdf_data);
static void	init_rotate(t_fdf *fdf_data);

/**
 * @brief Initialize the fdf structure.
 * @details Initialize the fdf structure by calling the needed nlx functions
 * @param file The file containing the map
 * @return *fdf_data The fdf structure allocated on the heap (must be freed)
 */
t_fdf	*fdf_init(char *file)
{
	t_fdf	*fdf_data;

	fdf_data = malloc(sizeof(t_fdf));
	if (!fdf_data)
		exit (1);
	init_tracker(fdf_data);
	fdf_data->altitude_factor = 1.0f;
	fdf_data->map = init_map(file);
	fdf_data->tracker->t_map_loaded = true;
	if (fdf_data->map == NULL)
		return (free(fdf_data), exit(3), NULL);
	fdf_data->mlx_win = malloc(sizeof(t_win));
	if (!fdf_data->mlx_win)
		exit_program(fdf_data);
	fdf_data->tracker->t_win_loaded = true;
	fdf_data->world = malloc(sizeof (t_world_i));
	fdf_data->tracker->t_world_loaded = true;
	if (!fdf_data->world)
		exit_program(fdf_data);
	nlx_win_init(fdf_data->mlx_win, WIDTH, HEIGHT, "FDF");
	get_world(fdf_data);
	get_proj(fdf_data);
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	get_cam_trans_speed(fdf_data);
	get_cam_rot_speed(fdf_data);
	get_cam_zoom_speed(fdf_data);
	return (fdf_data);
}

static void	get_proj(t_fdf *fdf_data)
{
	fdf_data->world->proj->aspect_ratio = (float)HEIGHT / (float)WIDTH;
	fdf_data->world->proj->fov = 90.0f;
	fdf_data->world->proj->z_near = 0.1f;
	fdf_data->world->proj->z_far = 1000.0f;
	fdf_data->world->proj->fov_rad = 1.0f
		/ tanf(fdf_data->world->proj->fov * 0.5f / 180.0f * (float)M_PI);
	fdf_data->world->proj->persp_m = get_persp_matrix(fdf_data->world->proj);
	if (WIDTH / fdf_data->map->width > HEIGHT / fdf_data->map->height)
		fdf_data->iso_factor = (float)HEIGHT / (float)fdf_data->map->height;
	else
		fdf_data->iso_factor = (float)WIDTH / (float)fdf_data->map->width;
	fdf_data->world->proj->iso_m = get_iso_matrix(fdf_data->iso_factor);
	if (fdf_data->world->proj_type == ISO)
		fdf_data->world->proj->current_m = fdf_data->world->proj->iso_m;
	else if (fdf_data->world->proj_type == PERSP)
		fdf_data->world->proj->current_m = fdf_data->world->proj->persp_m;
}

static void	get_world(t_fdf *fdf_data)
{
	fdf_data->world->key_is_pressed = false;
	fdf_data->world->key_pressed = 0;
	fdf_data->world->proj_type = ISO;
	fdf_data->world->trans = malloc(sizeof (t_trans_info));
	fdf_data->world->rot = malloc(sizeof (t_rot_info));
	fdf_data->world->proj = malloc(sizeof (t_proj_info));
	if (!fdf_data->world->trans || !fdf_data->world->rot
		|| !fdf_data->world->proj)
	{
		free(fdf_data->world->trans);
		free(fdf_data->world->rot);
		free(fdf_data->world->proj);
		free(fdf_data->world);
		fdf_data->tracker->t_world_loaded = false;
		exit_program(fdf_data);
	}
	init_translate(fdf_data);
	init_rotate(fdf_data);
	fdf_data->world->world_m = get_world_matrix(fdf_data->world);
	if (!fdf_data->world->world_m)
		exit_program(fdf_data);
}

static void	init_translate(t_fdf *fdf_data)
{
	if (fdf_data->map->width > fdf_data->map->height
		&& fdf_data->map->width > fdf_data->map->highest_point)
		fdf_data->world->trans->translate_z = fdf_data->map->width;
	else if (fdf_data->map->height > fdf_data->map->highest_point)
		fdf_data->world->trans->translate_z = fdf_data->map->height;
	else
		fdf_data->world->trans->translate_z = fdf_data->map->highest_point;
	fdf_data->world->trans->translate_x = 0.0f;
	fdf_data->world->trans->translate_y = 2.5f;
	fdf_data->world->trans->m = get_translation_matrix(fdf_data->world->trans);
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
