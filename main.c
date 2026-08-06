#include "ft_printf.h"

int	main(void)
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello");
	ft_printf("Number: %d\n", -42);
	ft_printf("Hexadecimal: %x\n", 255);
	return (0);
}