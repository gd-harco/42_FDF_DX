/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:58:53 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/24 11:12:30 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_tracker(t_fdf *fdf_data)
{
	fdf_data->tracker = malloc(sizeof(t_tracker));
	if (!fdf_data->tracker)
	{
		free(fdf_data);
		exit (3);
	}
	fdf_data->tracker->t_img_loaded = false;
	fdf_data->tracker->t_map_loaded = false;
	fdf_data->tracker->t_win_loaded = false;
	fdf_data->tracker->t_world_loaded = false;
}
