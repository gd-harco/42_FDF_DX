/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:46:29 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/04 15:49:12 by gd-harco         ###   ########lyon.fr   */
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

enum e_projection
{
	ISO,
	PERSPECTIVE,
}	e_projection;
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
	enum e_projection	proj_type;
}				t_fdf;

t_fdf	*fdf_init(char *file);

#endif
