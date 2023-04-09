/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:14:52 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/09 15:43:02 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "init.h"
#include <math.h>

static void	scale_in_view(t_vec3d *to_scale);

void	project_view(t_fdf *fdf_data)
{
	int	row;
	int	col;
	t_matrix	world;

	row = 0;
	world = get_world_matrix(get_z_rotation_matrix(0.0f), get_x_rotation_matrix(-(M_PI/4.0f)), get_y_rotation_matrix(0.0f), get_translation_matrix(0.0f, 2.5f, ));

	while (row < fdf_data->map->height)
	{

		col = 0;
		while (col < fdf_data->map->width)
		{
			multiply_vector_matrix(&world,
					&fdf_data->map->map_base[row][col],
					&fdf_data->map->map_projected[row][col]);
			col++;
		}
		row++;
	}
	row = 0;
	while (row < fdf_data->map->height)
	{
		col = 0;
		while (col < fdf_data->map->width)
		{
			multiply_vector_matrix(fdf_data->proj_info.m,
					&fdf_data->map->map_projected[row][col],
					&fdf_data->map->map_projected[row][col]);
			scale_in_view(&fdf_data->map->map_projected[row][col]);
			col++;
		}
		row++;
	}
}

static void	scale_in_view(t_vec3d *to_scale)
{
	to_scale->x = (to_scale->x + 1.0f) * 0.5f * (float)WIDTH;
	to_scale->y = (to_scale->y + 1.0f) * 0.5f *(float)HEIGHT;
}
