/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:27:22 by gd-harco          #+#    #+#             */
/*   Updated: 2022/10/30 19:27:22 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			x;

	x = 0;
	while (x < len)
	{
		((unsigned char *)b)[x] = (unsigned char)c;
		x++;
	}
	return (b);
}
