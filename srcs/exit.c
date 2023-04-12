/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:29:25 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/12 11:48:07 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_world(t_world_i *world);
static void	free_map(t_map *map);

int	exit_program(t_fdf *fdf_data)
{
	mlx_destroy_image(fdf_data->mlx_win->mlx, fdf_data->img.img_ptr);
	mlx_destroy_window(fdf_data->mlx_win->mlx, fdf_data->mlx_win->win_ptr);
	mlx_destroy_display(fdf_data->mlx_win->mlx);
	free_world(fdf_data->world);
	free_map(fdf_data->map);
	close(0);
	close(1);
	close(2);
	exit(0);
}

static void	free_world(t_world_i *world)
{
	free(world->proj->m);
	free(world->proj);
	free(world->trans->m);
	free(world->trans);
	free(world->rot->x_rot_m);
	free(world->rot->y_rot_m);
	free(world->rot->z_rot_m);
	free(world->rot);
	free(world->world_m);
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
