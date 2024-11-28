/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:18 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 12:28:19 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long arg, char c)
{
	char	*result;
	int		counter;

	if (c == 'x')
	{
		result = ft_itoa_hex((unsigned int)arg);
		counter = ft_printstr(result);
		free(result);
	}
	if (c == 'X')
	{
		result = ft_itoa_hex((unsigned int)arg);
		ft_toupper_str(result);
		counter = ft_printstr(result);
		free(result);
	}
	if (counter < 0)
		return (-1);
	else
		return (counter);
}
