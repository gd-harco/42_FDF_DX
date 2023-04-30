/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:01:16 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:27:50 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	update_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	update_projection(fdf->world->proj, fdf);
	project_view(fdf);
	draw_all(fdf);
}

void	change_fov(int key, t_fdf *fdf)
{
	if (fdf->world->proj_type == ISO)
		return ;
	if (key == XK_2)
		fdf->world->proj->fov = 90.0f;
	else if (key == XK_1)
		fdf->world->proj->fov = 60.0f;
	else if (key == XK_3)
		fdf->world->proj->fov = 120.0f;
	else if (key == XK_4)
		fdf->world->proj->fov = 150.0f;
	fdf->world->proj->fov_rad = 1.0f
		/ tanf(fdf->world->proj->fov * 0.5f / 180.0f * (float)M_PI);
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	update_projection(fdf->world->proj, fdf);
	project_view(fdf);
	draw_all(fdf);
}

void	change_altitude(int key, t_fdf *fdf)
{
	int	row;
	int	col;

	row = 0;
	if (key == XK_equal)
		fdf->altitude_factor += 0.01f;
	else
		fdf->altitude_factor -= 0.01f;
	while (row < fdf->map->height)
	{
		col = 0;
		while (col < fdf->map->width)
		{
			fdf->map->map_base[row][col].z
				= fdf->map->map_base[row][col].initial_z
				* fdf->altitude_factor;
			col++;
		}
		row++;
	}
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	update_projection(fdf->world->proj, fdf);
	project_view(fdf);
	draw_all(fdf);
}
