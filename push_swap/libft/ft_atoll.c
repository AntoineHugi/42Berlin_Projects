/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:34:46 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/06 13:00:37 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	long long	sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*nptr != '\0' && (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13)))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
		{
			sign = -sign;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10;
		result = result + *nptr - 48;
		nptr++;
	}
	return (sign * result);
}
