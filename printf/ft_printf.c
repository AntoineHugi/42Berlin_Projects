/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:58:37 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 12:27:43 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parameter_check(va_list args, char str)
{
	int	check;

	if (str == 's')
		check = ft_printstr(va_arg(args, char *));
	else if (str == 'i' || str == 'd' || str == 'u' || str == 'c')
		check = ft_printnum(va_arg(args, int), str);
	else if (str == 'x' || str == 'X')
		check = ft_printhex(va_arg(args, unsigned int), str);
	else if (str == 'p')
		check = ft_printpointer(va_arg(args, void *));
	else
		check = write(1, &str, 1);
	return (check);
}

int	ft_string_parser(const char *str, va_list args)
{
	int	counter;
	int	check;

	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
				break ;
			check = ft_parameter_check(args, *str);
		}
		else
			check = write(1, str, 1);
		if (check < 0)
			return (-1);
		counter += check;
		str++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;

	va_start(args, str);
	counter = ft_string_parser(str, args);
	va_end(args);
	if (counter < 0)
		return (-1);
	return (counter);
}
/*
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	test_int = -6809;
	int	test_d = 700;
	int	test_char = -1185;
	char	*test_string = "";
	unsigned int	test_x = 34522;
	void	*ptr = "";
	int	my_result;
	int	off_result;

	my_result = 0;
	off_result = 0;

	ft_printf("\n  my tests \n");
	my_result += ft_printf(" \
	i test is %i \n \
	d test is %d \n \
	c test is %c \n \
	s test is %s \n", \
	test_int, test_d, test_char, test_string);
	my_result += ft_printf(" \
	u test is %u \n \
	x test is %x \n \
	X test is %X \n \
	p test is %p \n \
	percent test is %%\n", \
	test_int, test_x, test_x, ptr);
	ft_printf("\n  official tests \n");
	off_result += printf(" \
	i test is %i \n \
	d test is %d \n \
	c test is %c \n \
	s test is %s \n", \
	test_int, test_d, test_char, test_string);
	off_result += printf(" \
	u test is %u \n \
	x test is %x \n \
	X test is %X \n \
	p test is %p \n \
	percent test is %%\n", \
	test_int, test_x, test_x, ptr);
	ft_printf("\nmy result: %i\n", my_result);
	ft_printf("official result: %i\n", off_result);
	return (my_result);
}*/