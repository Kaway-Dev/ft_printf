/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:36:20 by phkaway-          #+#    #+#             */
/*   Updated: 2026/08/05 12:01:40 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ulong(unsigned long n)
{
    int count;

    count = 0;
    if (n >= 16)
        count += ft_puthex_ulong(n / 16);
    count += ft_putchar("0123456789abcdef"[n % 16]);
    return(count);
}

int			ft_putptr(void *ptr)
{
    
}


int	ft_puthex(unsigned int n, char *base)
{
    int count;

    count = 0;
    if (n >= 16)
        count += ft_puthex(n / 16, base);
    count += ft_putchar(base[n % 16]);
    return (count);
}