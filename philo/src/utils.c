/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:11:49 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/31 17:39:32 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_numerical(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (i);
}

long long	ft_atoll(const char *nptr)
{
	long long	sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*nptr != '\0' && (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
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

void	get_time(time_t *time, t_table *table)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		error_table(table, "error getting time of day.");
	*time = now.tv_sec * 1000 + now.tv_usec / 1000;
}
