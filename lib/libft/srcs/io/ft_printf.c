/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:58:59 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/07 22:23:39 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "str.h"

ssize_t	ft_base_fd(size_t nbr, char *base, int fd)
{
	size_t	size;
	size_t	lenbase;

	size = 0;
	lenbase = ft_strlen(base);
	if (nbr >= lenbase)
		size += ft_base_fd(nbr / lenbase, base, fd);
	size += ft_putchar_fd(base[nbr % lenbase], fd);
	return (size);
}

int	print_required(char c, va_list args)
{
	size_t	buff;

	buff = 0;
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'u')
		return (ft_base_fd(va_arg(args, unsigned int), "0123456789", 1));
	if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1, 0));
	if (c == 'x')
		return (ft_base_fd(va_arg(args, unsigned int), "0123456789abcdef", 1));
	if (c == 'X')
		return (ft_base_fd(va_arg(args, unsigned int), "0123456789ABCDEF", 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	if (c == 'p')
	{
		buff += ft_putstr_fd("0x", 1);
		return (buff += ft_base_fd(va_arg(args, size_t), \
		"0123456789abcdef", 1));
	}
	return (0);
}

int	ft_printf(const char *txt, ...)
{
	va_list	args;
	int		i;
	int		final_size;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, txt);
	final_size = 0;
	if (!txt)
		return (0);
	while (*txt)
	{
		i = 0;
		while (txt[i] && txt[i] != '%')
			i++;
		final_size += write(1, txt, i);
		if (txt[i] == '%')
		{
			final_size += print_required(txt[++i], args);
			txt++;
		}
		txt += i;
	}
	return (final_size);
}
