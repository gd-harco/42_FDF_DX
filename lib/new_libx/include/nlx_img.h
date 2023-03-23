/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <mgd-harco@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:48:30 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/23 11:56:50 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLX_IMG_H
# define NLX_IMG_H
# include "../minilibx_linux/mlx.h"

//-----------------STRUCTURES-----------------//

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

//-----------------FUNCTIONS-----------------//

void	nlx_pixel_put(t_img *img, int x, int y, int color);
t_img	nlx_new_image(void *mlx, int width, int height);

#endif