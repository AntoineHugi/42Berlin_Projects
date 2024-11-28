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

static int	ft_string_parser(char str, va_list args)
{
	int	counter;

	if (str == 'c')
		counter = ft_printchar(va_arg(args, int));
	else if (str == 's')
		counter = ft_printstr(va_arg(args, char *));
	else if (str == 'i' || str == 'd' || str == 'u')
		counter = ft_printnum(va_arg(args, int), str);
	else if (str == 'x' || str == 'X')
		counter = ft_printhex(va_arg(args, unsigned long), str);
	else if (str == 'p')
		counter = ft_printpointer(va_arg(args, void *));
	else
		counter = write(1, &str, 1);
	if (counter < 0)
		return (-1);
	else
		return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		check;

	counter = 0;
	check = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check = ft_string_parser(*str, args);
		}
		else
			check = write(1, str, 1);
		if (check < 0)
			return (-1);
		else
			counter += check;
		str++;
	}
	va_end(args);
	return (counter);
}
