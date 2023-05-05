/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:01:27 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H
# include "nlx.h"

void	update_rotation(t_rot_info *rot);
void	update_translation(t_trans_info *trans);
void	update_projection(t_proj_info *proj, t_fdf *fdf);
void	update_world(t_world_i *world);
void	update_image(t_fdf *fdf);
void	change_render_mode(t_fdf *fdf);
void	change_cam_speed(int key, t_fdf *fdf);
#endif
