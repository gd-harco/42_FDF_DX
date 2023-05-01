/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:29:25 by gd-harco          #+#    #+#             */
/*   Updated: 2023/05/01 11:52:59 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_world(t_world_i *world, bool t_proj_loaded);
static void	free_map(t_map *map);

int	exit_program(t_fdf *fdf)
{
	if (fdf->tracker->t_img_loaded)
	{
		mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
		free(fdf->img);
	}
	if (fdf->tracker->t_win_loaded)
	{
		mlx_destroy_window(fdf->mlx_win->mlx, fdf->mlx_win->win_ptr);
		mlx_destroy_display(fdf->mlx_win->mlx);
		free(fdf->mlx_win->mlx);
		free(fdf->mlx_win);
	}
	if (fdf->tracker->t_world_loaded)
		free_world(fdf->world, fdf->tracker->t_proj_loaded);
	if (fdf->tracker->t_map_loaded)
		free_map(fdf->map);
	free(fdf->tracker);
	free(fdf->map_name);
	free(fdf);
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
	if (t_proj_loaded)
	{
		free(world->proj->persp_m);
		free(world->proj->iso_m);
	}
	free(world->proj);
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
