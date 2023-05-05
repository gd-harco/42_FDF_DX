/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:57:13 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/29 11:40:53 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parsing.c
 *
 * @brief FDF parsing file
 *
 * @author gd-harco
 * @date 2023-03-09
 */
#include "fdf.h"

static t_list	*put_file_in_list(int fd);
static t_map	*create_map(t_list *file_in_list);
static t_vec3d	**create_vec3d_array(t_list *file_in_list, t_map *map);
static t_vec3d	*create_vec3d_array_from_line(char *line, t_map *map, int y);

/**
 * @brief Initialize the map structure.
 * @details Initialize the map structure by calling the needed functions
 * @param map_file The file containing the map
 * @return *map The map structure allocated on the heap (must be freed)
 */

t_map	*init_map(char *map_file)
{
	t_list	*file_in_list;
	int		map_fd;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		return (perror("Error when opening map file\n"), NULL);
	file_in_list = put_file_in_list(map_fd);
	close(map_fd);
	if (!file_in_list)
		return (NULL);
	return (create_map(file_in_list));
}

/**
 * @brief Create a vec3d array from line object
 *
 * @param line
 * @param map
 * @param y
 * @return An arry of vec3d
 */
static t_vec3d	*create_vec3d_array_from_line(char *line, t_map *map, int y)
{
	t_vec3d	*vec3d_array;
	char	**splitted_line;
	int		x;

	splitted_line = ft_split(line, ' ');
	if (map->width != (int)ft_array_length((void **)splitted_line))
		return (ft_free_split(splitted_line),
			ft_dprintf(2, "Error parsing file at line %d\n", y + 1), NULL);
	vec3d_array = malloc(sizeof(t_vec3d) * map->width);
	if (!vec3d_array)
		return (ft_free_split(splitted_line),
			perror("Error when allocating memory for a line"),
			ft_dprintf(2, "Failed at line %d\n", y + 1), NULL);
	x = -1;
	while (++x < map->width)
	{
		vec3d_array[x].x = (float)x - (float)map->width / 2;
		vec3d_array[x].y = (float)y - (float)map->height / 2;
		vec3d_array[x].z = - (float)ft_atoi(splitted_line[x]);
		vec3d_array[x].initial_z = vec3d_array[x].z;
		vec3d_array[x].w = 1.0f;
	}
	ft_free_split(splitted_line);
	return (vec3d_array);
}

/**
 * @brief Create and allocate the map structure
 *
 * @param file_in_list The file containing the map
 * @return vec3d_array The map structure allocated on the heap (must be freed).
 */
static t_vec3d	**create_vec3d_array(t_list *file_in_list, t_map *map)
{
	t_vec3d	**vec3d_array;
	int		y;

	vec3d_array = ft_calloc(map->height, sizeof(t_vec3d *));
	if (!vec3d_array)
		return (perror("Error when allocating \"map_base\""), NULL);
	map->map_projected = ft_calloc(map->height, sizeof(t_vec3d *));
	if (!map->map_projected)
		return (perror("Error when allocating \"map_projected\""), NULL);
	y = 0;
	while (y < map->height)
	{
		vec3d_array[y] = create_vec3d_array_from_line(file_in_list->content,
				map, y);
		if (!vec3d_array[y])
			return (exit_file_not_regular(map, vec3d_array), NULL);
		map->map_projected[y] = malloc(sizeof(t_vec3d) * map->width);
		if (!map->map_projected[y])
			return (ft_dprintf(2, "Malloc failed at line %d\n", y + 1),
				exit_file_not_regular(map, vec3d_array), NULL);
		ft_bzero(map->map_projected[y], sizeof(t_vec3d) * map->width);
		file_in_list = file_in_list->next;
		y++;
	}
	return (vec3d_array);
}

/**
 * @brief Create and allocate the map structure
 *
 * @param file_in_list The file containing the map
 * @return t_map* The map structure allocated on the heap (must be freed).
 * At this state, th map_projected is allocated but empty.
 * The program must use the multiply_vector_matrix function to fill it.
 */
static t_map	*create_map(t_list *file_in_list)
{
	t_map	*map;
	char	**buff_for_width;

	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_lstclear(&file_in_list, &free),
			perror("Error when allocating memory for map\n"), NULL);
	map->height = ft_lstsize(file_in_list);
	buff_for_width = ft_split(file_in_list->content, ' ');
	if (!buff_for_width)
		return (ft_lstclear(&file_in_list, &free),
			perror("Error when allocating memory for map\n"), NULL);
	map->width = (int)ft_array_length((void **)buff_for_width);
	ft_free_split(buff_for_width);
	map->map_base = create_vec3d_array(file_in_list, map);
	if (!map->map_base)
	{
		free(map);
		return (ft_lstclear(&file_in_list, &free), NULL);
	}
	get_highest_point(map);
	ft_lstclear(&file_in_list, &free);
	return (map);
}

/**
 * @brief Put the file in a list of strings, used in the next function
 *
 * @param fd The file descriptor of the file
 * @return t_list*
 */
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
