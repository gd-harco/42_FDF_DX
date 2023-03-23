* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintest <mintest@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:39:07 by mintest           #+#    #+#             */
/*   Updated: 2023/03/21 14:58:49 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include"../lib/libft/includes/libft.h"
# include "mlx.h"
# include "parsing.h"
# include "struct.h"
# include "init.h"
# include "img.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef  WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 720
# endif

typedef struct s_fdf
{
	t_mlx		mlx;
	t_map_info	map;

}				t_fdf;

#endif
