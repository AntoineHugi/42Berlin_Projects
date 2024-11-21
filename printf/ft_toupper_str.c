#include "ft_printf.h"

void	ft_toupper_str(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
