/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:05:41 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/17 15:08:18 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	valid_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (0);
	else
	{
		if (ft_atoll(argv[1]) < 1)
			return (0);
		i = 1;
		while (i < argc)
		{
			if (ft_atoll(argv[i]) < 0 || ft_atoll(argv[i]) > 2147483647)
				return (0);
		}
	}
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


/*
Create threads for each philosophers, +1 thread for an observer to see if one dies.
Philos hold a spoon as soon as they can, and then hold on to it until they can grab another and eat.
Use mutex variables to "lock" forks when being held, and also for the printing of their updates (sleeping, eating etc).
Have a slight delay at the start for the even numbered philosophers (usleep 200), otherwise they each grab one fork and everyone dies.
Can't use libft for this project.
evaluations are tested with things like 5 800 200 200. They shouldn't die
*/
