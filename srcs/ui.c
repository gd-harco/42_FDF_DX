/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:23:51 by gd-harco          #+#    #+#             */
/*   Updated: 2023/05/01 11:54:49 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define COLOR_TEXT COLOR_SAND

static void	draw_ui_2(t_fdf *fdf);

void	draw_ui(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, WIDTH / 2 - 50, 30, COLOR_TEXT, fdf->map_name);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) - 175, COLOR_TEXT, TEXT_ROT);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) - 125, COLOR_TEXT, TEXT_MOVE);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) - 75, COLOR_TEXT, TEXT_ZOOM);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) - 25, COLOR_TEXT, TEXT_HEIGHT);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) + 25, COLOR_TEXT, TEXT_ISO);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) + 75, COLOR_TEXT, TEXT_PERSP);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) + 125, COLOR_TEXT, TEXT_RENDER);
	draw_ui_2(fdf);
}

static void	draw_ui_2(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) + 175, COLOR_TEXT, TEXT_EXIT);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) + 225, COLOR_TEXT, TEXT_FOV);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) + 275,
		COLOR_TEXT, TEXT_ZOOM_SPEED);
	mlx_string_put(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, 10, (HEIGHT / 2) + 325,
		COLOR_TEXT, TEXT_MOV_SPEED);
}
