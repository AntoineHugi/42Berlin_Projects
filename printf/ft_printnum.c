#include "ft_printf.h"

static int	ft_putnbr(long n)
{
	char	number;
	int		counter;
	int		check;

	if (n == 0)
		counter = write(1, "0", 1);
	else if (n < 0)
	{
		if (n == -2147483648)
			counter = write(1, "-2147483648", 11);
		else
			counter = write(1, "-", 1) + ft_putnbr(-n);
	}
	else
	{
		if (n >= 10)
			counter = ft_putnbr(n / 10);
		number = n % 10 + 48;
		check = write(1, &number, 1);
	}
	if (counter < 0 || check < 0)
		return (-1);
	else
		return (counter + check);
}

int	ft_printnum(int n, char c)
{
	int		counter;
	long	u;

	if (c == 'd' || c == 'i')
		counter = ft_putnbr(n);
	if (c == 'u')
	{
		if (n < 0)
			u = 4294967296 + n;
		else
			u = n;
		counter = ft_putnbr(u);
	}
	if (counter < 0)
		return (-1);
	else
		return (counter);
}
