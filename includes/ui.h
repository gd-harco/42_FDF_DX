/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:20:39 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 19:31:41 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "init.h"

//-----------------DEFINES----------------//

# define TEXT_ROT "W, A, S, D : rotate the map"
# define TEXT_MOVE "Up, Down, Left, Right : move the map"
# define TEXT_ZOOM "KeyPad +, KeyPad - : zoom in/out"
# define TEXT_HEIGHT "Number +, number - : increase/decrease height"
# define TEXT_ISO "I : switch to isometric projection"
# define TEXT_PERSP "P : switch to perspective projection"
# define TEXT_EXIT "ESC / Q : quit the program"
# define TEXT_RENDER "Space : toggle render mode"
# define TEXT_FOV "1, 2, 3, 4 : change FOV"
# define TEXT_ZOOM_SPEED "F1, F2 : change camera zoom speed"
# define TEXT_MOV_SPEED "F5, F6 : change camera translation speed"

//-----------------FUNCTIONS-----------------//
void	draw_ui(t_fdf *fdf);

#endif
