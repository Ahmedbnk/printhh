#include "ft_printf.h"

void print_string(char **str, va_list arg, t_infos *p_info,  int *p_count)
{
	(*str) ++;
	 char *content= va_arg(arg, char*);
	while (*content != '\0')
	{
		ft_putchar(*content, p_count);
		content ++;
	}
}
