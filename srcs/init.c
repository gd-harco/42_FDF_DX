/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:38 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/27 17:47:38 by gd-harco         ###   ########lyon.fr   */
/*
                                                                      */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*fdf_init(char *file)
{
	t_fdf	*fdf_data;

	fdf_data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf_data)
		return (NULL);
	fdf_data->map = init_map(file);
	nlx_win_init(fdf_data->mlx_win, WIDTH, HEIGHT, "FDF");
	return (fdf_data);

}
