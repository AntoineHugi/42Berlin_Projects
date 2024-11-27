#include "ft_printf.h"

static int	ft_num_size(unsigned long n)
{
	int	num_size;

	num_size = 1;
	while (n / 16 != 0)
	{
		num_size++;
		n = n / 16;
	}
	return (num_size);
}

char	*ft_itoa_hex_pointer(unsigned long n)
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
	if (n > (9223372036854775807))
		number[0] = '1';
	while (n != 0)
	{
		number[num_size - 1] = base_symbols[(n) % 16];
		n = n / 16;
		num_size--;
	}
	while (num_size-- > 1)
		number[num_size] = base_symbols[0];
	return (number);
}
