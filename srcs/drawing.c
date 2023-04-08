#include "fdf.h"

static t_nlx_line	**get_all_line(t_map *map, t_vec3d **dmap, int *nb_line);

void	draw_all(t_fdf *fdf_data)
{
	t_nlx_line	**all_line;
	int			nb_line;

	all_line = get_all_line(fdf_data->map,
			fdf_data->map->map_projected, &nb_line);
	while (nb_line)
	{
		nlx_draw_line(&fdf_data->img, *all_line, COLOR_BLUE);
		all_line++;
		nb_line--;
	}
	mlx_put_image_to_window(fdf_data->mlx_win->mlx, fdf_data->mlx_win->win_ptr, fdf_data->img.img_ptr, 0, 0);
}

t_nlx_line	**get_all_line(t_map *map, t_vec3d **dmap, int *nb_line)
{
	t_nlx_line	**lines;
	int			row;
	int			col;
	int			i;

	*nb_line = 2 * map->height * map->width - map->width - map->height;
	lines = malloc(sizeof(t_nlx_line) * (*nb_line));
	row = 0;
	i = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (col + 1 < map->width)
				lines[i++] = create_line(&dmap[row][col], &dmap[row][col + 1]);
			if (row + 1 < map->height)
				lines[i++] = create_line(&dmap[row][col], &dmap[row +1][col]);
			col++;
		}
		row++;
	}
	return (lines);
}