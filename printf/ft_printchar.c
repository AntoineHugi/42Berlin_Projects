#include "ft_printf.h"

int	ft_printchar(int c)
{
	if (c >= 0 && c <= 127)
		return (write(1, &c, 1));
	else if (c > 127 && c < 256)
		return (ft_printhex(c, 'x'));
	else
		return (write(1, "0", 1));
}
