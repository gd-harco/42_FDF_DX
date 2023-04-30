/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:39:07 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:28:48 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include"../lib/libft/includes/libft.h"
# include "drawing.h"
# include "exit.h"
# include "init.h"
# include "map.h"
# include "nlx.h"
# include "key_handler.h"
# include "projections.h"
# include "ui.h"
# include "update.h"
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>

# ifndef WIDTH
#  define WIDTH 1920
# endif
# ifndef HEIGHT
#  define HEIGHT 1080
# endif
#endif
