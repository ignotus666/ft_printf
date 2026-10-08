/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:40:11 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/07 11:48:13 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_and_return_len(const char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	process_fmt_str(const char *fmt_str, va_list args, int *len)
{
	int	prc_len;
	int	i;

	i = 0;
	while (fmt_str[i])
	{
		if (fmt_str[i] == '%')
		{
			prc_len = print_and_return_len(fmt_str[i + 1], args);
			if (prc_len == -1)
				return (-1);
			*len += prc_len;
			i++;
		}
		else
		{
			if (write (1, &fmt_str[i], 1) == -1)
				return (-1);
			*len += 1;
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	args;
	int		len;

	if (!fmt_str)
		return (-1);
	va_start (args, fmt_str);
	len = 0;
	if (process_fmt_str(fmt_str, args, &len) == -1)
		return (-1);
	va_end(args);
	return (len);
}
