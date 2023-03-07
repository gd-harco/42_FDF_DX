/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:24:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/06 15:24:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void	ft_free_split(void *splitted_element)
{
	size_t	i;

	if (splitted_element == NULL)
		return ;
	i = 0;
	while (((char **)splitted_element)[i])
		free(((char **)splitted_element)[i++]);
	free(splitted_element);
}
