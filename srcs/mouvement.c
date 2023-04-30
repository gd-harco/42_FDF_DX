/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:05:02 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(int key, t_fdf *fdf)
{
	if (key == XK_Up)
		fdf->world->trans->translate_y -= fdf->cam_trans_speed;
	else if (key == XK_Down)
		fdf->world->trans->translate_y += fdf->cam_trans_speed;
	else if (key == XK_Left)
		fdf->world->trans->translate_x -= fdf->cam_trans_speed;
	else if (key == XK_Right)
		fdf->world->trans->translate_x += fdf->cam_trans_speed;
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	update_translation(fdf->world->trans);
	update_world(fdf->world);
	project_view(fdf);
	draw_all(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == XK_w)
		fdf->world->rot->rot_x -= fdf->cam_rot_speed;
	else if (key == XK_s)
		fdf->world->rot->rot_x += fdf->cam_rot_speed;
	else if (key == XK_a)
		fdf->world->rot->rot_y -= fdf->cam_rot_speed;
	else if (key == XK_d)
		fdf->world->rot->rot_y += fdf->cam_rot_speed;
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	update_rotation(fdf->world->rot);
	update_world(fdf->world);
	project_view(fdf);
	draw_all(fdf);
}

void	zoom(int key, t_fdf *fdf)
{
	if (fdf->world->proj_type == ISO)
	{
		if (key == XK_KP_Add)
			fdf->iso_factor += fdf->cam_zoom_speed;
		else if (key == XK_KP_Subtract)
			fdf->iso_factor -= fdf->cam_zoom_speed;
		free(fdf->world->proj->iso_m);
		fdf->world->proj->iso_m = get_iso_matrix(fdf->iso_factor);
		fdf->world->proj->current_m = fdf->world->proj->iso_m;
	}
	else if (fdf->world->proj_type == PERSP)
	{
		if (key == XK_KP_Add)
			fdf->world->trans->translate_z -= fdf->cam_zoom_speed;
		else if (key == XK_KP_Subtract)
			fdf->world->trans->translate_z += fdf->cam_zoom_speed;
	}
	mlx_destroy_image(fdf->mlx_win->mlx, fdf->img->img_ptr);
	nlx_new_image(fdf->img, fdf->mlx_win->mlx, WIDTH, HEIGHT);
	update_translation(fdf->world->trans);
	update_world(fdf->world);
	project_view(fdf);
	draw_all(fdf);
}
