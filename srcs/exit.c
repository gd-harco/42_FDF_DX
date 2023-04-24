/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:29:25 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/24 11:59:18 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_world(t_world_i *world, bool t_proj_loaded);
static void	free_map(t_map *map);

int	exit_program(t_fdf *fdf_data)
{
	if (fdf_data->tracker->t_img_loaded)
		mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	if (fdf_data->tracker->t_win_loaded)
	{
		mlx_destroy_window(fdf_data->mlx_win->mlx, fdf_data->mlx_win->win_ptr);
		mlx_destroy_display(fdf_data->mlx_win->mlx);
		free(fdf_data->mlx_win->mlx);
		free(fdf_data->mlx_win);
	}
	if (fdf_data->tracker->t_world_loaded)
		free_world(fdf_data->world, fdf_data->tracker->t_proj_loaded);
	if (fdf_data->tracker->t_map_loaded)
		free_map(fdf_data->map);
	free(fdf_data->tracker);
	free(fdf_data);
	close(0);
	close(1);
	close(2);
	exit(0);
}

static void	free_world(t_world_i *world, bool t_proj_loaded)
{
	free(world->world_m);
	free(world->rot->x_rot_m);
	free(world->rot->y_rot_m);
	free(world->rot->z_rot_m);
	free(world->rot);
	free(world->trans->m);
	free(world->trans);
	free(world->proj);
	if (t_proj_loaded)
	{
		free(world->proj->persp_m);
		free(world->proj->iso_m);
	}
	free(world);
}

static void	free_map(t_map *map)
{
	while (map->height--)
	{
		free(map->map_base[map->height]);
		free(map->map_projected[map->height]);
	}
	free(map->map_base);
	free(map->map_projected);
	free(map);
}

void	exit_file_not_regular(t_map *map, t_vec3d **vec3d_array)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map_projected[i]);
		free(vec3d_array[i]);
		i++;
	}
	free(map->map_projected);
	free(vec3d_array);
}
