/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:46:29 by gd-harco          #+#    #+#             */
/*   Updated: 2023/05/01 11:45:15 by gd-harco         ###   ########lyon.fr   */
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

typedef struct s_tracker
{
	bool	t_map_loaded;
	bool	t_win_loaded;
	bool	t_img_loaded;
	bool	t_world_loaded;
	bool	t_proj_loaded;
}		t_tracker;

/**
 * @brief Structure containing all of the information needed in the program
 * @param map Map structure containing the map information
 * @param mlx_win structure containing the window information anf mlx pointer
 * @param img structure containing the image information
 * @param proj_info structure containing the projection information
 * @param iso_factor factor used to calculate the iso projection
 */
typedef struct s_fdf
{
	t_map		*map;
	t_win		*mlx_win;
	t_img		*img;
	t_world_i	*world;
	float		iso_factor;
	float		altitude_factor;
	float		cam_rot_speed;
	float		cam_trans_speed;
	float		cam_zoom_speed;
	t_tracker	*tracker;
	char		*map_name;
}				t_fdf;

t_fdf	*fdf_init(char *file);
void	get_cam_rot_speed(t_fdf *fdf);
void	get_cam_trans_speed(t_fdf *fdf);
void	get_cam_zoom_speed(t_fdf *fdf);
void	get_highest_point(t_map *map);
void	init_tracker(t_fdf *fdf);
void	sub_init(t_fdf *fdf);
#endif
