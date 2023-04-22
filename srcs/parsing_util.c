/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:13:48 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 17:20:09 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_highest_point(t_map *map)
{
	int	row;
	int	col;

	if (map->width == 0 || map->height == 0)
		return ;
	map->highest_point = INT_MIN;
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (map->map_base[row][col].initial_z > map->highest_point)
				map->highest_point = map->map_base[row][col].z;
			col++;
		}
		row++;
	}
}
