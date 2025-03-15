/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:13:49 by aben-hzz          #+#    #+#             */
/*   Updated: 2025/01/04 15:40:27 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char spec, va_list args, int *counter)
{
	char	ch;

	if (spec == 'c')
	{
		ch = (char)va_arg(args, int);
		ft_putchar(ch, counter);
	}
	else if (spec == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (spec == 'd' || spec == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (spec == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, counter);
	else if (spec == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, counter);
	else if (spec == 'p')
		ft_putptr(va_arg(args, void *), counter);
	else if (spec == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), counter);
	else if (spec == '%')
		ft_putchar('%', counter);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	args;

	if ((write (1, 0, 0) == -1) || format == NULL)
		return (-1);
	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (ft_conversion(*format, args, &counter) == -1)
				return (-1);
		}
		else
			ft_putchar(*format, &counter);
		format++;
	}
	va_end(args);
	return (counter);
}
