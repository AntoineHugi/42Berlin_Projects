/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:05:41 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/31 17:38:56 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* evaluations are tested with things like 5 800 200 200. They shouldn't die */
#include "../includes/philo.h"

int	valid_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (0);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_is_numerical(argv[i]))
				return (0);
			if (ft_atoll(argv[i]) < 1 || ft_atoll(argv[i]) > INT_MAX)
				return (0);
			i++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (valid_input(argc, argv))
	{
		table = init_table(argv);
		if (!table)
			error_table(table, "error initialising table.");
		start_meal(table);
	}
	else
		error_arguments();
}
