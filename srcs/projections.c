/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:14:52 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/09 17:39:36 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "init.h"
#include <math.h>

static void	get_world(t_fdf *fdf_data);

static void	scale_in_view(t_vec3d *to_scale);

void	project_view(t_fdf *fdf_data)
{
	int			row;
	int			col;
	t_vec3d		tmp;

	row = 0;
	fdf_data->map->highest_point = -fdf_data->map->highest_point;
	get_world(fdf_data);
	while (row < fdf_data->map->height)
	{

		col = 0;
		while (col < fdf_data->map->width)
		{
			multiply_vector_matrix(fdf_data->world.world,
				&fdf_data->map->map_base[row][col],
				&tmp);
			multiply_vector_matrix(fdf_data->world.proj->m,
				&tmp,
				&fdf_data->map->map_projected[row][col]);
			scale_in_view(&fdf_data->map->map_projected[row][col]);
			col++;
		}
		row++;
	}
}

void	vector_divide(t_vec3d *a, float k)
{
	if (k == 0)
		return ;
	a->x /= k;
	a->y /= k;
	a->z /= k;
	a->w = 1.0f;
}

static void	scale_in_view(t_vec3d *to_scale)
{
	vector_divide(to_scale, to_scale->w);
	to_scale->x = (to_scale->x + 1.0f) * (float)WIDTH / 2.0f + 0.5f;
	to_scale->y = (to_scale->y + 1.0f) * (float)HEIGHT / 2.0f + 0.5f;
}


void	get_world(t_fdf *fdf_data)
{
	if (fdf_data->map->width > fdf_data->map->height
		&& fdf_data->map->width > fdf_data->map->highest_point)
		fdf_data->world.trans->translate_z = fdf_data->map->width;
	else if (fdf_data->map->height > fdf_data->map->highest_point)
		fdf_data->world.trans->translate_z = fdf_data->map->height;
	else
		fdf_data->world.trans->translate_z = fdf_data->map->highest_point;
	fdf_data->world.trans->translate_x = 0.0f;
	fdf_data->world.trans->translate_y = 2.5f;
	fdf_data->world.rot->rot_x = (-(M_PI/4.0f));
	fdf_data->world.rot->rot_y = 0.0f;
	fdf_data->world.rot->rot_z = 0.0f;
	fdf_data->world.world = get_world_matrix(&fdf_data->world);
}
