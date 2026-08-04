#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1;
    int ret2;


    ret1 = ft_printf("Ola mundo");
    ret2 = printf("Ola mundo");

    printf("ft_printf retornou: %d\n", ret1);
    printf("printf retornou: %d\n", ret2);
    return (0);
}

