/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:08:09 by gd-harco          #+#    #+#             */
/*   Updated: 2022/10/27 19:08:09 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include "str.h"

static char	*itoa_min_null(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	return (ft_strdup("0"));
}

static char	*filling(int n, int x, char *converted)
{
	if (n < 0)
	{
		n *= -1;
		while (x > 0)
		{
			converted[--x] = (n % 10) + '0';
			n /= 10;
		}
		converted[x] = '-';
	}
	else
	{
		while (x > 0)
		{
			converted[--x] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (converted);
}

char	*ft_itoa(int n)
{
	size_t		x;
	int			nb;
	char		*converted;

	if ((n == (-2147483647 -1)) || n == 0)
		return (itoa_min_null(n));
	x = 1;
	nb = n;
	if (n < 0)
		x++;
	while (!(nb < 10 && nb > -10) && x++)
		nb /= 10;
	converted = malloc(sizeof(char) * x + 1);
	if (!converted)
		return (NULL);
	converted[x] = '\0';
	return (filling(n, x, converted));
}
