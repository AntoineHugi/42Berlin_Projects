#include "ft_printf.h"

static int	ft_num_size(long n)
{
	int	num_size;

	if (n == 0)
		num_size = 1;
	else if (n > (4294960487/2))
		num_size = 9;
	else
		num_size = 8;
	return (num_size);
}

char	*ft_itoa_hex_pointer(long n)
{
	char	*base_symbols;
	char	*number;
	int		num_size;

	base_symbols = "0123456789abcdef";
	num_size = ft_num_size(n);
	number = (char *)malloc((num_size + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[num_size] = 0;
	if (n == 0)
		number[0] = '0';
	if (num_size == 9)
		number[0] = '1';
	while (n != 0)
	{
		number[num_size - 1] = base_symbols[(n) % 16];
		n = n / 16;
		num_size--;
	}
	while (num_size > 1)
	{
		number[num_size - 1] = base_symbols[0];
		num_size--;
	}
	return (number);
}
