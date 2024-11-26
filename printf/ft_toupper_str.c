#include "ft_printf.h"

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

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
