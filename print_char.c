#include "ft_printf.h"
void	print_char(char c, int *p_count, t_infos *p_infos)
{
	while(p_infos -> width > 0 && p_infos -> dash == 0)
	{
		write(1, " ", 1);
		(*p_count) ++;
		p_infos -> width --;
	}
	write(1, &c, 1);
	(*p_count) ++;
	while(p_infos -> width > 0 && p_infos -> dash == 1)
	{
		write(1, " ", 1);
		(*p_count) ++;
		p_infos -> width --;
	}

}
