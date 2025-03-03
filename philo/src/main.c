/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:05:41 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/27 11:22:06 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philo(char **argv)
{
	t_philo	*philo;

	philo = (t_philo*)malloc(sizeof(t_philo));
	philo->ttd = argv[2];
	philo->tte = argv[3];
	philo->tts = argv[4];
	philo->is_dead = 0;
	philo->times_eaten = 0;
}

t_table	*init_table(char **argv)
{
	int		i;
	t_table	*table;

	i = 0;
	table = (t_table*)malloc(sizeof(t_table));
	table->philos=(t_philo**)malloc((ft_atoi(argv[1]) - 1) * sizeof(t_philo*));
	while (i < ft_atoi(argv[1]))
	{
		table->philos[i] = init_philo(**argv);
		if (i%2 == 0)
			table->philos[i]->ttt = table->philos[i]->tts;
		else
			table->philos[i]->ttt = table->philos[i]->tts/2;
		i++;
	}
	return (table);
}


int	valid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	else
	{
		if (ft_atoll(argv[1]) < 1)
			return (0);
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
		init_philo(argv);
	}
}


/*
Create threads for each philosophers, +1 thread for an observer to see if one dies.
Philos hold a spoon as soon as they can, and then hold on to it until they can grab another and eat.
Use mutex variables to "lock" forks when being held, and also for the printing of their updates (sleeping, eating etc).
Have a slight delay at the start for the even numbered philosophers (usleep 200), otherwise they each grab one fork and everyone dies.
Can't use libft for this project.
evaluations are tested with things like 5 800 200 200
*/