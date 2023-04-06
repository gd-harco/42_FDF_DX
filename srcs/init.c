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
	fdf_data->mlx_win = (t_win *)malloc(sizeof(t_win));
	fdf_data->proj_info.aspect_ratio = (float)WIDTH / (float)HEIGHT;
	fdf_data->proj_info.fov = 90.0f;
	fdf_data->proj_info.z_near = 0.1f;
	fdf_data->proj_info.z_far = 1000.0f;
	fdf_data->proj_info.fov_rad = 1.0f
		/ tanf(fdf_data->proj_info.fov * 0.5f / 180.0f * (float)M_PI);
	fdf_data->proj_info.m = get_projection_matrix(&fdf_data->proj_info);
	nlx_win_init(fdf_data->mlx_win, WIDTH, HEIGHT, "FDF");
	return (fdf_data);
}
