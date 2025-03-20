/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:11:49 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/17 15:40:15 by ahugi            ###   ########.fr       */
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

void	error_arguments()
{
	printf("Invalid arguments, please provide 4 or 5 arguments:\n");
	printf("Number of philosophers (at least 1, but less than 200)\n");
	printf("Time until death (in ms), time to eat (in ms), ");
	printf("time to sleep (in ms)\n");
	printf("(optional) Number of times each philo should have ");
	printf("eaten to end the meal.\n");
	printf("Example: 5 800 200 200 3\n");
	exit(1);
}

void	error_table(t_table *table, char *msg)
{
	free_table(table);
	printf("%s\n", msg);
	exit(1);
}
