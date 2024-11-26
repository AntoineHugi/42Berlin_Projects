#include "ft_printf.h"

int	ft_printpointer(void *arg, char c)
{
	char	*result;
	int		counter;

	
	counter = 0;
	if (c == 'p')
	{
		result = ft_itoa_hex_pointer((long)arg);
		counter += write (1, "0x", 2);
		counter += ft_printstr(&result[0]);
		free(result);
	}
	return (counter);
}
