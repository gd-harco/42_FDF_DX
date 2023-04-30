/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:14:52 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "init.h"

static void	set_visibility(t_vec3d *vec, float z_near);
static void	scale_in_view(t_vec3d *to_scale);
static void	scale_in_view_iso(t_vec3d *to_scale);

void	project_view(t_fdf *fdf)
{
	int			row;
	int			col;
	t_vec3d		tmp;

	row = 0;
	fdf->map->highest_point = -fdf->map->highest_point;
	while (row < fdf->map->height)
	{
		col = 0;
		while (col < fdf->map->width)
		{
			multiply_vector_matrix(fdf->world->world_m,
				&fdf->map->map_base[row][col], &tmp);
			multiply_vector_matrix(fdf->world->proj->current_m,
				&tmp, &fdf->map->map_projected[row][col]);
			if (fdf->world->proj_type == PERSP)
				scale_in_view(&fdf->map->map_projected[row][col]);
			if (fdf->world->proj_type == ISO)
				scale_in_view_iso(&fdf->map->map_projected[row][col]);
			set_visibility(&fdf->map->map_projected[row][col],
				fdf->world->proj->z_near);
			col++;
		}
		row++;
	}
}

void	set_visibility(t_vec3d *vec, float z_near)
{
	if (vec->w < z_near)
		vec->is_behind_camera = true;
	else
		vec->is_behind_camera = false;
}

void	vector_divide(t_vec3d *a, float k)
{
	if (k == 0)
		return ;
	a->x /= k;
	a->y /= k;
	a->z /= k;
}

static void	scale_in_view_iso(t_vec3d *to_scale)
{
	to_scale->x = (to_scale->x + 1.0f) + (float)WIDTH / 2.0f + 0.5f;
	to_scale->y = (to_scale->y + 1.0f) + (float)HEIGHT / 2.0f + 0.5f;
}

static void	scale_in_view(t_vec3d *to_scale)
{
	vector_divide(to_scale, to_scale->w);
	to_scale->x = (to_scale->x + 1.0f) * (float)WIDTH / 2.0f + 0.5f;
	to_scale->y = (to_scale->y + 1.0f) * (float)HEIGHT / 2.0f + 0.5f;
}
