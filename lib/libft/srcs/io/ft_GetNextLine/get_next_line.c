/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:28:22 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/07 22:36:10 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*final_read(char buf[BUFFER_SIZE + 1], int reading, char *str)
{
	move_buf(buf, BUFFER_SIZE);
	if (reading < 0)
	{
		if (str)
			free (str);
		return (NULL);
	}
	return (str);
}

char	*joined(char buf[BUFFER_SIZE + 1], char *str)
{
	str = gnl_join(str, buf, index_of(buf, '\n') + 1);
	if (str)
		move_buf(buf, index_of(buf, '\n') + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			reading;

	if (fd == -1 || fd > OPEN_MAX)
		return (NULL);
	reading = 1;
	str = NULL;
	while (reading > 0)
	{
		if (index_of(buf[fd], '\n') != -1)
			return (joined(buf[fd], str));
		if (buf[fd][0])
		{
			str = gnl_join(str, buf[fd], ft_strlen(buf[fd]));
			if (!str)
				return (NULL);
			move_buf(buf[fd], BUFFER_SIZE);
		}
		reading = read(fd, buf[fd], BUFFER_SIZE);
	}
	if (reading <= 0)
		return (final_read(buf[fd], reading, str));
	free (str);
	return (NULL);
}
