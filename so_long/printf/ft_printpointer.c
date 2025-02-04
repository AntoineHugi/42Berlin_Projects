/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:33 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 12:28:37 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *arg)
{
	char	*result;
	int		counter;
	int		check;

	if (!arg)
		return (write(1, "(nil)", 5));
	result = ft_itoa_hex_pointer((unsigned long)arg);
	if (!result)
		return (-1);
	check = write(1, "0x", 2);
	if (check < 0)
	{
		free(result);
		return (-1);
	}
	counter = ft_printstr(result);
	free(result);
	if (counter < 0)
		return (-1);
	return (counter + check);
}
