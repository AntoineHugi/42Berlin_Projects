#include "ft_printf.h"

int	ft_printhex(unsigned int arg, char c)
{
	char	*result;
	int		counter;

	counter = 0;
	if (c == 'x')
	{
		result = ft_itoa_hex((unsigned int)arg);
		counter += ft_printstr(result);
		free(result);
	}
	if (c == 'X')
	{
		result = ft_itoa_hex((unsigned int)arg);
		ft_toupper_str(result);
		counter += ft_printstr(result);
		free(result);
	}
	if (c == 'p')
	{
		result = ft_itoa_hex_pointer((unsigned int)arg);
		counter += write (1, "0x", 2);
		counter += ft_printstr(&result[0]);
		free(result);
	}
	return (counter);
}
