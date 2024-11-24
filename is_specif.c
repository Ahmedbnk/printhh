#include "ft_printf.h"

int is_specif(char c)
{
	if (c =='c'||c=='s'||c=='p'||c=='d'||c=='i'||c=='u'||c=='X'||c=='x')
	{
		return (1);
	}
	return (0);
}
