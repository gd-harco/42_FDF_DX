/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:30 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/07 22:26:41 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*s)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

int	index_of(char buf[BUFFER_SIZE +1], char r)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == r)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_join(char *str, char buff[BUFFER_SIZE + 1], size_t	len)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(sizeof(char) * (ft_strlen(str) + len + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
		{
			result[i] = str[i];
			i++;
		}
	}
	while (len--)
		result[i++] = buff[j++];
	result[i] = '\0';
	if (str)
		free (str);
	return (result);
}

void	move_buf(char buf[BUFFER_SIZE + 1], size_t index)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = ft_strlen(buf);
	while (buf[x])
	{
		if (x + index < y)
			buf[x] = buf[x + index];
		else
			buf[x] = '\0';
		x++;
	}
}
