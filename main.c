#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret;

ret = ft_printf("Unsigned: %u\n", 4294967295u);
printf("Retorno: %d\n", ret);
    return (0);
}

