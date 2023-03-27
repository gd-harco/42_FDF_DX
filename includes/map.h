/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:33 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/27 16:05:26 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "nlx.h"

typedef struct s_map
{
	t_vec3D	**map_base;
	t_vec3D	**map_projected;
	int		width;
	int		height;
}				t_map;

#endif
