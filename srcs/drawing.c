
#include "fdf.h"

static t_nlx_line **get_all_line(t_map *map, t_vec3d **dmap, int *nb_line, t_img *img);

void	draw_all(t_fdf *fdf_data)
{
	t_nlx_line	**all_line;
	int			nb_line;
	int			i;

	i = 0;
	all_line = get_all_line(fdf_data->map,
							fdf_data->map->map_projected, &nb_line, &fdf_data->img);
	while (nb_line)
	{
		if (all_line [i]->is_visible)
			nlx_draw_line(&fdf_data->img, all_line[i], COLOR_BLUE);
		i++;
		free(all_line[i - 1]);
		nb_line--;
	}
	free(all_line);
	mlx_put_image_to_window(fdf_data->mlx_win->mlx,
		fdf_data->mlx_win->win_ptr, fdf_data->img.img_ptr, 0, 0);
}

/**
 * @brief Get all the line to draw
 * @details The function create a t_nlx_line for each line to draw
 * @param map the map structure
 * @param dmap the map projected
 * @param nb_line the number of line to draw
 * @allocated_on Heap (must be freed)
 * @return t_nlx_line** the array of t_nlx_line
 */
t_nlx_line **get_all_line(t_map *map, t_vec3d **dmap, int *nb_line, t_img *img)
{
	t_nlx_line	**lines;
	int			row;
	int			col;
	int			i;

	*nb_line = 2 * map->height * map->width - map->width - map->height;
	lines = malloc(sizeof(t_nlx_line) * (*nb_line));
	if (!lines)
		return (NULL);
	row = 0;
	i = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (col + 1 < map->width)
				lines[i++] = create_line(&dmap[row][col], &dmap[row][col + 1], img);
			if (row + 1 < map->height)
				lines[i++] = create_line(&dmap[row][col], &dmap[row + 1][col], img);
			col++;
		}
		row++;
	}
	return (lines);
}
