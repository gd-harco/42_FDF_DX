/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:29:52 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/23 15:08:04 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "init.h"

int		exit_program(t_fdf *fdf_data);
void	exit_file_not_regular(t_map *map, t_vec3d **vec3d_array);

#endif
