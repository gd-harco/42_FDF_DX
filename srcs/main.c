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
	mlx_loop(fdf_data->mlx_win->mlx);
	(void)fdf_data;
	return (0);
}
