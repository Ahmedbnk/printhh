#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
typedef	struct s_infos{
	int width;
	int dash;
	int zero;
	int dot;
	int square;
	int space;
	int plus;
}t_infos;

void	start_infos(t_infos *infos);
void    ft_putchar(char c, int *p_count);
void	print_char(char c, int *p_count, t_infos *p_infos);
void	print_string(char **str, va_list arg, t_infos *p_info,  int *p_count);
int	is_specif(char c);
int	is_flag(char c);
int     ft_atoi(char **str);
#endif
