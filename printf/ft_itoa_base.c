#include "ft_printf.h"

static int	ft_num_size(int n)
{
	int	num_size;

	num_size = 1;
	if (n < 0)
	{
		num_size++;
	}
	while (n / 10 != 0)
	{
		num_size++;
		n = n / 10;
	}
	return (num_size);
}

char	*ft_itoa_base(unsigned int n, int base)
{
	char	*base_symbols;
	char	*number;
	int		num_size;
	int		sign;

	base_symbols = "0123456789abcdef";
	sign = 1;
	num_size = ft_num_size(n);
	number = (char *)ft_calloc((num_size + 1), sizeof(char));
	if (!number)
		return (NULL);
	if (n == 0)
		number[0] = '0';
	if (n < 0)
	{
		number[0] = '-';
		sign = -sign;
	}
	while (n != 0)
	{
		number[num_size - 1] = base_symbols[(sign * n) % base];
		n = n / base;
		num_size--;
	}
	return (number);
}
