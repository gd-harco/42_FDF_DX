/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:46:29 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 13:14:04 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_cam_rot_speed(t_fdf *fdf)
{
	int	n;
	int	i;

	n = fdf->map->height * fdf->map->width;
	i = 10;
	while (n)
	{
		i--;
		n /= 10;
	}
	if (i == 0)
		fdf->cam_rot_speed = (0.25f * 1.0f * 0.025);
	else
		fdf->cam_rot_speed = (0.25f * (float)i * 0.025);
}

void	get_cam_zoom_speed(t_fdf *fdf)
{
	fdf->cam_zoom_speed = fdf->cam_rot_speed * 3;
}

void	get_cam_trans_speed(t_fdf *fdf)
{
	int		multiplied;
	int		divisor;
	double	tmp;

	multiplied = fdf->map->height * fdf->map->width;
	tmp = multiplied;
	divisor = 1;
	while (multiplied)
	{
		multiplied /= 10;
		divisor++;
	}
	tmp = tmp / (float)divisor;
	if (tmp > 500.0)
		fdf->cam_trans_speed = (tmp * 0.0001);
	fdf->cam_trans_speed = (0.25);
}
