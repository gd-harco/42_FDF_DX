/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:46:29 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/27 17:57:08 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "map.h"
# include "nlx.h"

typedef struct s_fdf
{
	t_map		*map;
	t_win		*mlx_win;
	t_img		img;
	t_proj_info	proj_info;
}				t_fdf;

t_fdf	*fdf_init(char *file);

#endif
