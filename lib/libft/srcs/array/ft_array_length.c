/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:38:25 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/16 18:34:23 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_array_length(void **array)
{
	size_t	x;

	if (!array)
		return (0);
	x = 0;
	while (array[x])
		x++;
	return (x);
}
