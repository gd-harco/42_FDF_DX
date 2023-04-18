/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:46:29 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/18 18:28:26 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init.h
 *
 * @brief FDF initialization header file
 *
 * @author gd-harco
 * @date 2023/03/27
 */

#ifndef INIT_H
# define INIT_H

# include "map.h"
# include "nlx.h"

/**
 * @brief Structure containing all of the information needed in the program
 * @param map Map structure containing the map information
 * @param mlx_win structure containing the window information anf mlx pointer
 * @param img structure containing the image information
 * @param proj_info structure containing the projection information
 */
typedef struct s_fdf
{
	t_map				*map;
	t_win				*mlx_win;
	t_img				img;
	t_world_i			*world;
}				t_fdf;

t_fdf	*fdf_init(char *file);

#endif
