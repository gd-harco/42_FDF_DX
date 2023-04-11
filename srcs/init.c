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

	fdf_data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf_data)
		return (NULL);
	fdf_data->map = init_map(file);
	if (fdf_data->map == NULL)
	{
		free(fdf_data);
		exit (3);
	}
	fdf_data->mlx_win = malloc(sizeof(t_win));
	fdf_data->world = malloc(sizeof (t_world_i));
	if (!fdf_data->mlx_win || !fdf_data->world)
		return (NULL);
	get_world(fdf_data);
	get_proj(fdf_data);
	nlx_win_init(fdf_data->mlx_win, WIDTH, HEIGHT, "FDF");
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
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
	fdf_data->world->proj->m = get_projection_matrix(fdf_data->world->proj);
}

static void	get_world(t_fdf *fdf_data)
{
	fdf_data->world->trans = malloc(sizeof (t_trans_info));
	fdf_data->world->rot = malloc(sizeof (t_rot_info));
	fdf_data->world->proj = malloc(sizeof (t_proj_info));
	fdf_data->world->world_m = malloc(sizeof (t_matrix));
	if (fdf_data->world->trans == NULL
		|| fdf_data->world->rot == NULL
		|| fdf_data->world->proj == NULL
		|| fdf_data->world->world_m == NULL)
		exit(0);
	init_translate(fdf_data);
	init_rotate(fdf_data);
	fdf_data->world->world_m = get_world_matrix(fdf_data->world);
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

static void	init_rotate(t_fdf *fdf_data)
{
	fdf_data->world->rot->rot_x = (-(M_PI/4.0f));
	fdf_data->world->rot->rot_y = 0.0f;
	fdf_data->world->rot->rot_z = 0.0f;
	fdf_data->world->rot->x_rot_m
		= get_x_rotation_matrix(fdf_data->world->rot->rot_x);
	fdf_data->world->rot->y_rot_m
		= get_y_rotation_matrix(fdf_data->world->rot->rot_y);
	fdf_data->world->rot->z_rot_m
		= get_z_rotation_matrix(fdf_data->world->rot->rot_z);
}
