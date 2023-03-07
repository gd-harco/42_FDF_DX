/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:27:19 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/05 10:38:47 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static size_t	in_charset(char c, char *charset)
{
	size_t	x;

	x = 0;
	while (charset[x])
	{
		if (c == charset[x])
			return (1);
		x++;
	}
	return (0);
}

static char	*look_for_start(char const *s, char const *set)
{
	char	*start;

	start = (char *)s;
	while (*start)
	{
		if (in_charset((char)*start, (char *)set))
			start++;
		else
			return (start);
	}
	return (NULL);
}

static char	*look_for_end(char const *s, char const *set)
{
	char	*end;
	size_t	len;

	len = ft_strlen(s) - 1;
	end = (char *)s + len;
	while (len > 0)
	{
		if (in_charset((char)*end, (char *)set))
		{
			end--;
			len--;
		}
		else
			return (end);
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	size_t	len;
	char	*result;
	size_t	x;

	if (!s1 || !set)
		return (NULL);
	start = look_for_start(s1, set);
	if (!start)
		return (ft_strdup(""));
	end = (look_for_end(s1, set) + 1);
	len = end - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	x = 0;
	while (len > 0)
	{
		result[x++] = *start++;
		len--;
	}
	result[x] = '\0';
	return (result);
}
