/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:09:47 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 13:19:03 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./fdf <filename>.fdf");
		exit(1);
	}
	fdf = fdf_init(argv[1]);
	project_view(fdf);
	fdf->tracker->t_proj_loaded = true;
	draw_all(fdf);
	mlx_hook(fdf->mlx_win->win_ptr, KeyPress,
		KeyPressMask, key_handler_in, fdf);
	mlx_hook(fdf->mlx_win->win_ptr, KeyRelease,
		KeyReleaseMask, key_handler_out, fdf);
	mlx_loop_hook(fdf->mlx_win->mlx, loop_hook, fdf);
	mlx_hook(fdf->mlx_win->win_ptr, 17, 0, exit_program, fdf);
	mlx_loop(fdf->mlx_win->mlx);
	return (0);
}

/**
 * @brief Initialize the fdf structure.
 * @details Initialize the fdf structure by calling the needed nlx functions
 * @param file The file containing the map
 * @return *fdf The fdf structure allocated on the heap (must be freed)
 */
t_fdf	*fdf_init(char *file)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		exit (1);
	init_tracker(fdf);
	fdf->altitude_factor = 1.0f;
	fdf->map = init_map(file);
	fdf->tracker->t_map_loaded = true;
	if (fdf->map == NULL)
		return (free(fdf), exit(3), NULL);
	fdf->mlx_win = malloc(sizeof(t_win));
	if (!fdf->mlx_win)
		exit_program(fdf);
	fdf->tracker->t_win_loaded = true;
	fdf->world = malloc(sizeof (t_world_i));
	fdf->tracker->t_world_loaded = true;
	if (!fdf->world)
		exit_program(fdf);
	sub_init(fdf);
	return (fdf);
}
