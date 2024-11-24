/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:52:28 by abenkrar          #+#    #+#             */
/*   Updated: 2024/11/24 01:34:48 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	operate_mandatory(char **str, va_list arg, t_infos *p_infos,
		int *p_count)
{
	if (**str == 'c')
	{
		(*str)++;
		print_char(va_arg(arg, int), p_count, p_infos);
	}
	else if (**str == 's')
	{
		print_string(str, arg, p_infos, p_count);
	}
	/*	else if (**str == 'p')
			print_pointer(str, arg, p_count);
		else if (**str == 'd' || **str == 'i')
			print_number(str, arg, p_count);
		else if (**str == 'u')
			print_unsigned(str, arg, p_count);
		else if (**str == 'x')
			print_lower_hexa(str, arg, p_count);
		else if (**str == 'X')
			print_upper_hexa(str, arg, p_count);*/
}

void	operate_flags(char **str, va_list arg, t_infos *p_infos, int *p_count)
{
	if (**str >= '0' && **str <= '9')
	{
		p_infos->width = ft_atoi(str);
		return ;
	}
	else if (**str == '.')
		p_infos->dot = 1;
	else if (**str == '-')
		p_infos->dash = 1;
	else if (**str == '0')
		p_infos->zero = 1;
	else if (**str == '#')
		p_infos->square = 1;
	else if (**str == ' ')
		p_infos->space = 1;
	else if (**str == '+')
		p_infos->plus = 1;
	(*str)++;
}

void	operate(char **str, va_list arg, t_infos *p_infos, int *p_count)
{
	while (**str)
	{
		if (**str == '%')
		{
			(*str)++;
			start_infos(p_infos);
			if (**str == '%')
			{
				ft_putchar(**str, p_count);
				(*str)++;
			}
			else if (is_specif(**str) == 1)
				operate_mandatory(str, arg, p_infos, p_count);
			else if (is_flag(**str) == 1)
			{
				while (is_flag(**str) == 1)
					operate_flags(str, arg, p_infos, p_count);
				if (is_specif(**str) == 1)
					operate_mandatory(str, arg, p_infos, p_count);
			}
		}
		else if (**str != '%' && **str != '\0')
		{
			ft_putchar(**str, p_count);
			(*str)++;
		}
	}
}

int	ft_printf(const char *string, ...)
{
	int		count;
	va_list	arg;
	t_infos	*infos;
	char	**str;

	str = (char **)&string;
	count = 0;
	infos = malloc(sizeof(t_infos));
	if (infos == NULL)
		return (-1);
	va_start(arg, string);
	operate(str, arg, infos, &count);
	va_end(arg);
	free(infos);
	return (count);
}

int	main(void)
{
	char	x;
	char	*y;
	int		count;

	x = 'x';
	y = "haaaaa";
	// ft_printf("hskdhd%%hskd");
	count = ft_printf("%10c", x);
	return (0);
}
