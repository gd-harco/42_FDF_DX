/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintest <mintest@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:52:40 by mintest           #+#    #+#             */
/*   Updated: 2023/03/17 14:46:59 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec3d
{
	float	x;
	float	y;
	float	z;
}				t_vec3d;

typedef struct s_matrix
{
	float	mat[4][4];
}				t_matrix;

typedef struct s_map_info
{
	size_t	height;
	size_t	width;
	t_vec3d	**map;
	t_vec3d	**map_to_draw;
}				t_map_info;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx;
#endif
