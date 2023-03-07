/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintest <mintest@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:39:07 by mintest           #+#    #+#             */
/*   Updated: 2023/03/07 15:52:54 by mintest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/libft/includes/libft.h"
# include "mlx.h"
# include "parsing.h"
# include "struct.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_fdf
{
	t_map_info	map;
}				t_fdf;

#endif