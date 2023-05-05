/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:14:03 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLER_H
# define KEY_HANDLER_H

# include <X11/keysym.h>

//-----------------FUNCTIONS-----------------//
int		loop_hook(t_fdf *fdf);
int		key_handler_in(int key, t_fdf *fdf);
int		key_handler_out(int key, t_fdf *fdf);
int		change_cam(int key, t_fdf *fdf);
void	translate(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	zoom(int key, t_fdf *fdf);
void	change_fov(int key, t_fdf *fdf);
void	change_altitude(int key, t_fdf *fdf);
void	change_projection(int key, t_fdf *fdf);
#endif
