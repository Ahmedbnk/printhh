#include "ft_printf.h"
void    ft_putchar(char c, int *p_count)
{
		(*p_count) ++;
		write(1, &c, 1);
}

