/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:46:29 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Base values set for the map "42.fdf", which is 19x11
every other map will be scaled to fit these values*/

void	get_cam_rot_speed(t_fdf *fdf)
{
	fdf->cam_rot_speed = 0.03f;
}

void	get_cam_zoom_speed(t_fdf *fdf)
{
	fdf->cam_zoom_speed = fdf->cam_rot_speed * 3;
}

void	get_cam_trans_speed(t_fdf *fdf)
{
	fdf->cam_trans_speed = (0.10f);
}
