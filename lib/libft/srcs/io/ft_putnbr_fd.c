/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:38:02 by gd-harco          #+#    #+#             */
/*   Updated: 2022/10/23 18:38:02 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include <unistd.h>

size_t	ft_putnbr_fd(int n, int fd, size_t size)
{
	if (n == -2147483647 -1)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return ((ft_putnbr_fd((-1 * n), fd, size)) + 1);
	}
	else if (n >= 10)
	{
		size += ft_putnbr_fd((n / 10), fd, size);
		size += ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
		return (ft_putchar_fd((n + '0'), fd));
	return (size);
}
