/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 13:04:31 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/07 12:32:41 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	s_len;

	if (!s)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	s_len = 0;
	while (s[s_len])
	{
		if (write (1, &s[s_len], 1) == -1)
			return (-1);
		s_len++;
	}
	return (s_len);
}

int	ft_putnbr(long nbr)
{
	char	conv_num;
	int		len;

	len = 0;
	if (nbr < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		nbr = -nbr;
		len++;
	}
	if (nbr > 9)
	{
		len += ft_putnbr(nbr / 10);
		if (len == -1)
			return (-1);
	}
	conv_num = (nbr % 10) + '0';
	len++;
	if (write (1, &conv_num, 1) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr_hex(unsigned long nbr, char *base)
{
	char			conv_num;
	int				len;

	len = 0;
	if (nbr > 15)
	{
		len += ft_putnbr_hex(nbr / 16, base);
		if (len == -1)
			return (-1);
	}
	conv_num = (base[nbr % 16]);
	len++;
	if (write (1, &conv_num, 1) == -1)
		return (-1);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	str_len;

	if (!ptr)
	{
		if (write (1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	len = 2;
	str_len = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	str_len = ft_putnbr_hex((unsigned long)ptr, "0123456789abcdef");
	if (str_len == -1)
		return (-1);
	len += str_len;
	return (len);
}
