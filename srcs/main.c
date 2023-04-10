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

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf_data;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./fdf <filename>.fdf");
		exit(1);
	}
	fdf_data = fdf_init(argv[1]);
	project_view(fdf_data);
	draw_all(fdf_data);
	mlx_key_hook(fdf_data->mlx_win->win_ptr, key_handler, fdf_data);
	mlx_hook(fdf_data->mlx_win->win_ptr, 17, 0, exit_program, fdf_data);
	mlx_loop(fdf_data->mlx_win->mlx);
	(void)fdf_data;
	return (0);
}
