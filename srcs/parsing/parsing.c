/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:57:13 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/28 12:41:25 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*put_file_in_list(int fd);

t_map	*init_map(char *map_file)
{
	t_map	*map;
	t_list	*file_in_list;
	int		map_fd;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		return (perror("Error when opening map file\n"), NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	file_in_list = put_file_in_list(map_fd);
	if (!file_in_list)
		return (NULL);
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
			exit(1);
		}
		ft_lstadd_back(&list, new_node);
		buff = get_next_line(fd);
	}
	return (list);
}

