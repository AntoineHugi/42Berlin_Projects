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

	if (!arg)
		counter = write (1, "(nil)", 5);
	else
	{
		result = ft_itoa_hex_pointer((unsigned long)arg);
		counter = write (1, "0x", 2) + ft_printstr(&result[0]);
		free(result);
	}
	if (counter < 0)
		return (-1);
	else
		return (counter);
}
