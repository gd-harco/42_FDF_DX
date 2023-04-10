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
	fdf_data->world = malloc(sizeof(t_world_i));
	fdf_data->mlx_win = (t_win *)malloc(sizeof(t_win));
	fdf_data->world->proj->aspect_ratio = (float)HEIGHT / (float)WIDTH;
	fdf_data->world->proj->fov = 90.0f;
	fdf_data->world->proj->z_near = 0.1f;
	fdf_data->world->proj->z_far = 1000.0f;
	fdf_data->world->proj->fov_rad = 1.0f
		/ tanf(fdf_data->world->proj->fov * 0.5f / 180.0f * (float)M_PI);
	fdf_data->world->proj->m = get_projection_matrix(fdf_data->world->proj);
	nlx_win_init(fdf_data->mlx_win, WIDTH, HEIGHT, "FDF");
	nlx_new_image(&fdf_data->img, fdf_data->mlx_win->mlx, WIDTH, HEIGHT);
	return (fdf_data);
}
