/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:25:55 by gd-harco          #+#    #+#             */
/*   Updated: 2022/11/08 15:37:56 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

// Localise un string dans un autre,
// renvoie un pointeur vers le premier caractere du string localise, ou NULL

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		x;
	size_t		y;

	if (!needle[0])
		return ((char *)haystack);
	x = 0;
	while (x < len && haystack[x])
	{
		if (haystack[x] == needle[0])
		{
			y = 0;
			while (haystack[x + y] == needle[y] && (x + y) < len)
			{
				y++;
				if (!needle[y])
					return ((char *)&haystack[x]);
			}
		}
		x++;
	}
	return (NULL);
}
