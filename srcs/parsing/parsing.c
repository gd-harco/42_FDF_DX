/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:57:13 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/29 11:00:29 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*put_file_in_list(int fd);
static t_map	*create_map(t_list *file_in_list);
static t_vec3d	**create_vec3d_array(t_list *file_in_list, t_map *map);
static t_vec3d	*create_vec3d_array_from_line(char *line, t_map *map, int y);

t_map	*init_map(char *map_file)
{
	t_list	*file_in_list;
	int		map_fd;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		return (perror("Error when opening map file\n"), NULL);
	file_in_list = put_file_in_list(map_fd);
	if (!file_in_list)
		return (NULL);
	return (create_map(file_in_list));
}

static t_vec3d	*create_vec3d_array_from_line(char *line, t_map *map, int y)
{
	t_vec3d	*vec3d_array;

	vec3d_array = malloc(sizeof(t_vec3d) * map->width);
	if (!vec3d_array)
		return (perror("Error when allocating memory for map\n"), NULL);
	fill_vec3d_array(vec3d_array, line, map, y);
	return (vec3d_array);
}

static void	fill_vec3d_array(t_vec3d *vec3d_array, char *line, t_map *map, int y)
{
	char	**split_line;
	int		x;

	split_line = ft_split(line, ' ');
	x = -1;
	while (++x < map->width)
	{
		vec3d_array[x].x = x;
		vec3d_array[x].y = y;
		vec3d_array[x].z = ft_atoi(split_line[x]);
	}
}

static t_vec3d	**create_vec3d_array(t_list *file_in_list, t_map *map)
{
	t_vec3d	**vec3d_array;
	int		y;

	vec3d_array = malloc(sizeof(t_vec3d *) * map->height);
	if (!vec3d_array)
		return (perror("Error when allocating memory for map\n"), NULL);
	y = 0;
	while (y < map->height)
	{
		vec3d_array[y] = create_vec3d_array_from_line(file_in_list->content,
				map, y);
		file_in_list = file_in_list->next;
		y++;
	}
	return (vec3d_array);
}

static t_map	*create_map(t_list *file_in_list)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (perror("Error when allocating memory for map\n"), NULL);
	map->height = ft_lstsize(file_in_list);
	map->map_base = create_vec3d_array(file_in_list, map);
	map->map_projected = create_vec3d_array(file_in_list, map);
	return (map);
}

static t_list	*put_file_in_list(int fd)
{
	t_list	*list;
	t_list	*new_node;
	char	*buff;

	list = NULL;
	buff = get_next_line(fd);
	while (buff)
	{
		new_node = ft_lstnew(buff);
		if (new_node == NULL)
		{
			ft_lstclear(&list, &free);
			exit(3);
		}
		ft_lstadd_back(&list, new_node);
		buff = get_next_line(fd);
	}
	return (list);
}
