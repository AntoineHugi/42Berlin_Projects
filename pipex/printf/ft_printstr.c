/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:44 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 12:28:47 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	counter;
	int	check;

	counter = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		check = ft_printchar(*str);
		if (check < 0)
			return (-1);
		counter += check;
		str++;
	}
	return (counter);
}
