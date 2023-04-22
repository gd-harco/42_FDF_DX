/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:33 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 17:23:16 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "nlx.h"

//-----------------STRUCTURES-----------------//

/**
 * @brief Structure containing the map information
 * @param map_base 2D array of t_vec3d containing the map information
 * @param map_projected 2D array of t_vec3d containing the projected map
 * @param width width of the map
 * @param height height of the map
 * @param highest_point highest point of the map
 */
typedef struct s_map
{
	t_vec3d	**map_base;
	t_vec3d	**map_projected;
	int		width;
	int		height;
	float	highest_point;
}				t_map;

//-----------------FUNCTIONS-----------------//

t_map	*init_map(char *map_file);

#endif
