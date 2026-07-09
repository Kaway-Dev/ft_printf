#include <stdio.h>

int main(void)
{
    int ret;
    ret = printf("%s", (char*)NULL);
    printf("\nretorno: %d\n", ret);
    return (0);
}

// Testando o comportamento de NULL da ft_putstr.