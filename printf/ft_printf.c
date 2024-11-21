/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:58:37 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/21 13:58:39 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_num_param_base_16(long arg, char c)
{
	char	*result;

	if (c == 'x')
	{
		result = ft_itoa_base(arg, 16);
		write (1, "0x", 2);
		ft_putstr_fd(result, 1);
		free(result);
	}
	if (c == 'X')
	{
		result = ft_itoa_base(arg, 16);
		ft_toupper_str(result);
		write (1, "0x", 2);
		ft_putstr_fd(result, 1);
		free(result);
	}
	if (c == 'p')
	{
		write (1, "0x", 2);
		ft_putstr_fd((char *)arg, 1);
	}
}

static void	ft_num_param_base_10(int arg, char c)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(arg, 1);
	if (c == 'u')
		ft_putnbr_fd((unsigned int)arg, 1);
}

static void	ft_str_param(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return ;
	}
	ft_putstr_fd(str, 1);
}

static void	ft_string_parser(const char *str, va_list args)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_putchar_fd((char)va_arg(args, int), 1);
			else if (*str == 's')
				ft_str_param(va_arg(args, char *));
			else if (*str == 'i' || *str == 'd' || *str == 'u')
				ft_num_param_base_10(va_arg(args, int), *str);
			else if (*str == 'x' || *str == 'X' || *str == 'p')
				ft_num_param_base_16(va_arg(args, long), *str);
			else
				write(1, str, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_string_parser(str, args);
	va_end(args);
	return (0);
}
/*
int	main(void)
{
	int	test_int = -70;
	int	test_d = 700;
	char	test_char = 'A';
	char	*test_string = "beans";
	void	*ptr = &test_int;
	int	test_percentage = 3;

	ft_printf("\n easier tests first \n");
	ft_printf("i test is %i \nd test is %d \nc test is %c \ns test is %s \n", test_int, test_d, test_char, test_string);

	ft_printf("\n harder tests next \n");
	ft_printf("x test is %x \n X test is %X \n p test is %p \n percent test is %%\n", test_int, test_int, ptr, test_percentage);
	return(0);
}*/
