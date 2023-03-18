/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintest <mintest@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:54:32 by mintest           #+#    #+#             */
/*   Updated: 2023/03/17 15:23:10 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf_data;

	if (argc != 2)
	{
		ft_putstr_fd("ERROR : no file provided\n", STDERR_FILENO);
		exit(1);
	}
	fdf_data.map = parsing(argv[1]);
	start_mlx(&fdf_data);
	(void)fdf_data;
	return (0);
}
