/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:02:52 by gd-harco          #+#    #+#             */
/*   Updated: 2022/11/08 13:05:53 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	x;

	if (!dst && !src)
		return (NULL);
	x = 0;
	if (src < dst)
	{
		if (len == 0)
			return (dst);
		x = len - 1;
		while (x > 0)
		{
			((char *)dst)[x] = ((char *)src)[x];
			x--;
		}
		((char *)dst)[x] = ((char *)src)[x];
		return (dst);
	}
	else if (src > dst)
	{
		return (ft_memcpy(dst, src, len));
	}
	return (dst);
}
