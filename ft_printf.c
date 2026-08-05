/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:20:28 by phkaway-          #+#    #+#             */
/*   Updated: 2026/08/05 15:39:28 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parser(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (specifier == '%')
		return (ft_putchar('%'));
	if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_put_unsigned(va_arg(*args, unsigned int)));
	if (specifier == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (specifier == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start (args, fmt);
	i = 0;
	count = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			count += ft_parser(fmt[i + 1], &args);
			i += 2;
		}
		else
		{
			count += ft_putchar(fmt[i]);
			i++;
		}
	}
	va_end (args);
	return (count);
}
