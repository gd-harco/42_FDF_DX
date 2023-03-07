/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:29:19 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/14 14:29:19 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strpdup(const char *s1, int index)
{
	char	*s2;
	size_t	len;
	int		i;

	len = ft_strlen(s1 + index) + 1;
	s2 = malloc(len * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[index + i])
	{
		s2[i] = s1[index + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
