/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:14:52 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/06 15:14:52 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:46:30 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/04 18:47:23 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "init.h"

void	project_view(t_fdf *fdf_data)
{
	int	row;
	int	col;

	row = 0;
	while (row < fdf_data->map->height)
	{
		col = 0;
		while (col < fdf_data->map->width)
		{
			multiply_vector_matrix(fdf_data->proj_info.m,
					&fdf_data->map->map_base[row][col],
					&fdf_data->map->map_projected[row][col]);
			col++;
		}
		row++;
	}
}
