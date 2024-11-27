#include "ft_printf.h"

static int	ft_string_parser(const char *str, va_list args)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				counter += ft_printchar(va_arg(args, int));
			else if (*str == 's')
				counter += ft_printstr(va_arg(args, char *));
			else if (*str == 'i' || *str == 'd' || *str == 'u')
				counter += ft_printnum(va_arg(args, int), *str);
			else if (*str == 'x' || *str == 'X' || *str == 'p')
				counter += ft_printhex(va_arg(args, unsigned long), *str);
			else
				counter += write(1, str, 1);
		}
		else
			counter += write(1, str, 1);
		str++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, str);
	counter = ft_string_parser(str, args);
	va_end(args);
	return (counter);
}
