/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:43:16 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 13:26:42 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIONS_H
# define PROJECTIONS_H
# include "init.h"

void	iso(t_fdf *fdf);
void	project_view(t_fdf *fdf);
void	iso_project_view(t_fdf *fdf);
#endif
