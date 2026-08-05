/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:20:28 by phkaway-          #+#    #+#             */
/*   Updated: 2026/08/04 23:07:38 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_parser(char specifier, va_list *args)
{
    if (specifier == 'c')
        return (ft_putchar(va_arg(*args, int)));
    if (specifier == '%')
        return (ft_putchar('%'));
    if (specifier == 's')
        return (ft_putstr(va_arg(*args, char *)));
    return (0);
}

int ft_printf(const char *fmt, ...)
{
    va_list args;
    int i;
    int count;

    va_start(args, fmt);
    i = 0;
    count = 0;
    while(fmt[i] != '\0')
    {
        if(fmt[i] == '%')
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
    va_end(args);
    return(count);
}
