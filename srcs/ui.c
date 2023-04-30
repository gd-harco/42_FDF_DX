/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:23:51 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/29 17:50:33 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_ui(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 10, 20, COLOR_WHITE, TEXT_EXIT);
	mlx_string_put(mlx_ptr, win_ptr, 10, 40, COLOR_WHITE, TEXT_ROT);
	mlx_string_put(mlx_ptr, win_ptr, 10, 60, COLOR_WHITE, TEXT_MOVE);
	mlx_string_put(mlx_ptr, win_ptr, 10, 80, COLOR_WHITE, TEXT_ZOOM);
	mlx_string_put(mlx_ptr, win_ptr, 10, 100, COLOR_WHITE, TEXT_HEIGHT);
	mlx_string_put(mlx_ptr, win_ptr, 10, 120, COLOR_WHITE, TEXT_ISO);
	mlx_string_put(mlx_ptr, win_ptr, 10, 140, COLOR_WHITE, TEXT_PERSP);
}
