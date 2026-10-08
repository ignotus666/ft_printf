/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:27:27 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/07 12:26:11 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt_str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long nbr);
int	ft_putnbr_hex(unsigned long nbr, char *base);
int	ft_putptr(void *ptr);

#endif