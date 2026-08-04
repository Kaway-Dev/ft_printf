/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:20:28 by phkaway-          #+#    #+#             */
/*   Updated: 2026/08/04 18:34:28 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(fmt[i] != '\0')
    {
        ft_putchar(fmt[i]);
        count++;
        i++;
    }
    return(count);
}
