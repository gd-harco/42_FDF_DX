/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:39:07 by mintest           #+#    #+#             */
/*   Updated: 2023/03/27 16:19:24 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include"../lib/libft/includes/libft.h"
# include "nlx.h"
# include "parsing.h"
# include "init.h"
# include "map.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef  WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 720
# endif

typedef struct t_mlx
{
	void	*mlx_ptr;
	t_win	*win;
}			t_mlx;


typedef struct s_fdf
{
	t_map		map;
	t_mlx		mlx;
	t_img		img;
	t_matrix	*matrix;
}				t_fdf;



#endif
