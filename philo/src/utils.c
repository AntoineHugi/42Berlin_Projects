/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:11:49 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/27 11:12:21 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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