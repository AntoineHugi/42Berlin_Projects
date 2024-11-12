/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:22:48 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/11 17:23:17 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_size(int n)
{
	int	num_size;

	num_size = 1;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			return (11);
		}
		n = -n;
		num_size++;
	}
	while (n / 10 > 0)
	{
		num_size++;
		n = n / 10;
	}
	return (num_size);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		num_size;

	num_size = ft_num_size(n);
	number = (char *)malloc(sizeof(char) * num_size + 1);
	number[num_size] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			number = "-2147483648";
			return (number);
		}
		number[0] = '-';
		n = -n;
		num_size--;
	}
	while (num_size > 0)
	{
		number[num_size] = n % 10 + 48;
		n = n / 10;
		num_size--;
	}
	return (number);
}
