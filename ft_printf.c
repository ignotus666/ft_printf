/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:40:11 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/05 13:10:14 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(const char type, va_list args)
{
	
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start (args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check(format[i + 1], args);
		}
	}
}
