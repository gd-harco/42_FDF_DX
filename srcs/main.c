/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:09:47 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/24 13:01:18 by gd-harco         ###   ########lyon.fr   */
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
	fdf_data->tracker->t_proj_loaded = true;
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

/**
 * @brief Initialize the fdf structure.
 * @details Initialize the fdf structure by calling the needed nlx functions
 * @param file The file containing the map
 * @return *fdf_data The fdf structure allocated on the heap (must be freed)
 */
t_fdf	*fdf_init(char *file)
{
	t_fdf	*fdf_data;

	fdf_data = malloc(sizeof(t_fdf));
	if (!fdf_data)
		exit (1);
	init_tracker(fdf_data);
	fdf_data->altitude_factor = 1.0f;
	fdf_data->map = init_map(file);
	fdf_data->tracker->t_map_loaded = true;
	if (fdf_data->map == NULL)
		return (free(fdf_data), exit(3), NULL);
	fdf_data->mlx_win = malloc(sizeof(t_win));
	if (!fdf_data->mlx_win)
		exit_program(fdf_data);
	fdf_data->tracker->t_win_loaded = true;
	fdf_data->world = malloc(sizeof (t_world_i));
	fdf_data->tracker->t_world_loaded = true;
	if (!fdf_data->world)
		exit_program(fdf_data);
	sub_init(fdf_data);
	return (fdf_data);
}
