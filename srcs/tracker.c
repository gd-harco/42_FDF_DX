/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:58:53 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_tracker(t_fdf *fdf)
{
	fdf->tracker = malloc(sizeof(t_tracker));
	if (!fdf->tracker)
	{
		free(fdf);
		exit (3);
	}
	fdf->tracker->t_img_loaded = false;
	fdf->tracker->t_map_loaded = false;
	fdf->tracker->t_win_loaded = false;
	fdf->tracker->t_world_loaded = false;
	fdf->tracker->t_proj_loaded = false;
}
