/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:25 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 12:28:27 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(long n)
{
	int		counter;
	int		check;

	counter = 0;
	check = 0;
	if (n == 0)
		counter = write(1, "0", 1);
	else if (n < 0)
	{
		check = write(1, "-", 1);
		if (check < 0)
			return (-1);
		counter = ft_putnbr(-n);
	}
	else
	{
		if (n >= 10)
			counter = ft_putnbr(n / 10);
		if (counter < 0)
			return (-1);
		check = ft_printchar(n % 10 + 48);
	}
	if (counter < 0 || check < 0)
		return (-1);
	return (counter + check);
}

int	ft_printnum(int n, char c)
{
	int		counter;
	long	u;

	counter = 0;
	if (c == 'c')
		counter = ft_printchar(n);
	else if (c == 'd' || c == 'i')
		counter = ft_putnbr(n);
	else if (c == 'u')
	{
		if (n < 0)
			u = (unsigned int)n;
		else
			u = n;
		counter = ft_putnbr(u);
	}
	return (counter);
}
