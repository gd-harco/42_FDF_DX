/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:23:51 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 19:33:53 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define COLOR_TEXT COLOR_SAND

void	draw_ui(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 -175, COLOR_TEXT, TEXT_ROT);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 - 125, COLOR_TEXT, TEXT_MOVE);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 - 75, COLOR_TEXT, TEXT_ZOOM);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 - 25, COLOR_TEXT, TEXT_HEIGHT);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 + 25, COLOR_TEXT, TEXT_ISO);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 + 75, COLOR_TEXT, TEXT_PERSP);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 + 125, COLOR_TEXT, TEXT_RENDER);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, 540 + 175, COLOR_TEXT, TEXT_EXIT);
}
