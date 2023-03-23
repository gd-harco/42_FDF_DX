/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:49 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/23 11:56:50 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_img.h"

t_img	nlx_new_image(void *mlx, int width, int height)
{
	t_img	img;

	img.img = mlx_new_image(mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.width = width;
	img.height = height;
	return (img);
}

void	nlx_pixel_put(t_img	*img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}