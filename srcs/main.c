/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:09:47 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/20 14:42:22 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//TODO reparer le changement d'altitude
//TODO ajouter le get _rot/zoom speed
//TODO regler le niveau de zoom par dafaut en proj iso
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
	mlx_hook(fdf_data->mlx_win->win_ptr, KeyPress,
		KeyPressMask, key_handler_in, fdf_data);
	mlx_hook(fdf_data->mlx_win->win_ptr, KeyRelease,
		KeyReleaseMask, key_handler_out, fdf_data);
	mlx_loop_hook(fdf_data->mlx_win->mlx, loop_hook, fdf_data);
	mlx_hook(fdf_data->mlx_win->win_ptr, 17, 0, exit_program, fdf_data);
	mlx_loop(fdf_data->mlx_win->mlx);
	return (0);
}
