#include "ft_printf.h"

int is_flag(char c)
{
	if ((c >= '0' && c <= '9') || c =='.'||c=='-'||c=='#'||c==' '||c=='+')
	{
		return (1);
	}
	return (0);
}
