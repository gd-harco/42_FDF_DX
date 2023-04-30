/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:34:34 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool			check_for_null(t_nlx_line **lines, int nb_line);
static void			create_line_duet(
						t_fdf *fdf, t_vec3d **dmap, t_nlx_line **lines);
static t_nlx_line	**get_all_line(
						t_fdf *fdf, t_vec3d **dmap, int *nb_line);

void	draw_all(t_fdf *fdf)
{
	t_nlx_line	**all_line;
	int			nb_line;
	int			i;

	i = 0;
	all_line = get_all_line(fdf,
			fdf->map->map_projected, &nb_line);
	if (all_line == NULL || check_for_null(all_line, nb_line))
		exit_program(fdf);
	while (nb_line)
	{
		if (all_line[i]->is_visible && fdf->world->render_type == 0)
			nlx_draw_line(fdf->img, all_line[i], COLOR_WHITE);
		else if (all_line[i]->is_visible && fdf->world->render_type == 1)
			nlx_draw_points(fdf->img, all_line[i], COLOR_WHITE);
		i++;
		free(all_line[i - 1]);
		nb_line--;
	}
	free(all_line);
	mlx_put_image_to_window(fdf->mlx_win->mlx,
		fdf->mlx_win->win_ptr, fdf->img->img_ptr, 0, 0);
	draw_ui(fdf);
}

/**
 * @brief Get all the line to draw
 * @details The function create a t_nlx_line for each line to draw
 * @param fdf the map structure
 * @param dmap the map projected
 * @param nb_line the number of line to draw
 * @allocated_on Heap (must be freed)
 * @return t_nlx_line** the array of t_nlx_line
 */
t_nlx_line	**get_all_line(t_fdf *fdf, t_vec3d **dmap, int *nb_line)
{
	t_nlx_line	**lines;

	*nb_line = 2 * fdf->map->height * fdf->map->width
		- fdf->map->width - fdf->map->height;
	lines = malloc(sizeof(t_nlx_line) * (*nb_line));
	if (!lines)
		return (perror("Error when creating the lines"), NULL);
	create_line_duet(fdf, dmap, lines);
	return (lines);
}

static void	create_line_duet(t_fdf *fdf, t_vec3d **dmap, t_nlx_line **lines)
{
	int	row;
	int	col;
	int	i;

	i = 0;
	row = 0;
	while (row < fdf->map->height)
	{
		col = 0;
		while (col < fdf->map->width)
		{
			if (col + 1 < fdf->map->width)
				lines[i++] = create_line
					(&dmap[row][col], &dmap[row][col + 1], fdf->img);
			if (row + 1 < fdf->map->height)
				lines[i++] = create_line
					(&dmap[row][col], &dmap[row + 1][col], fdf->img);
			col++;
		}
		row++;
	}
}

static bool	check_for_null(t_nlx_line **lines, int nb_line)
{
	int	i;

	i = 0;
	while (i < nb_line)
	{
		if (lines[i] == NULL)
		{
			perror("Error when creating the lines");
			ft_dprintf(2, "Line %d is NULL\n", i);
			i = 0;
			while (i < nb_line)
				free(lines[i++]);
			free(lines);
			return (true);
		}
		i++;
	}
	return (false);
}
