/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:09:47 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/06 15:13:26 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:54:32 by mintest           #+#    #+#             */
/*   Updated: 2023/04/05 13:58:11 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//#include <stdio.h>
//void print_map(t_vec3d **map)
//{
//	int row;
//	int col;
//
//	row = 0;
//	while (row <= 9)
//	{
//		col = 0;
//		while (col <= 19)
//		{
//			printf("%d ", (int)map[row][col].z);
//			col++;
//		}
//		printf("\n");
//		row++;
//	}
//}

int	main(int argc, char **argv)
{
	t_fdf	*fdf_data;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./fdf <filename>.fdf");
		exit(1);
	}
	fdf_data = fdf_init(argv[1]);
//	//TODO remove this
//	print_map(fdf_data->map->map_base);
	project_view(fdf_data);
	draw_all(fdf_data);
	mlx_loop(fdf_data->mlx_win->mlx);
	(void)fdf_data;
	return (0);
}
