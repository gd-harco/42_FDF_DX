/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:02:48 by gd-harco          #+#    #+#             */
/*   Updated: 2022/10/21 22:02:48 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static size_t	get_length(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	size_t	y;

	if (start > ft_strlen(s))
		return (0);
	x = start;
	y = 0;
	if (len == 0)
		return (0);
	if (len == start)
		return (len);
	while (s[x] && x < (len + start))
	{
		x++;
		y++;
	}
	return (y);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	result_length;
	size_t	x;

	if (s == NULL)
		return (NULL);
	result_length = get_length(s, start, len);
	result = malloc(sizeof(char) * (result_length + 1));
	if (result == NULL)
		return (NULL);
	x = 0;
	while (x < result_length)
	{
		result[x] = s[start];
		x++;
		start++;
	}
	result[x] = '\0';
	return (result);
}
