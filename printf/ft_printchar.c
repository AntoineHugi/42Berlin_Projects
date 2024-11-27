#include "ft_printf.h"

int	ft_printchar(int c)
{
	unsigned int		uc;
	int		counter;

	uc = (unsigned int)c;
	counter = write(1, &uc, 1);
	return (counter);
}
