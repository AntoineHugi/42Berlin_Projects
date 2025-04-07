#include "../includes/philo.h"

void	start_timer(t_table *table)
{
	if (gettimeofday(&table->start, NULL) == -1)
		error_table(table, "error recording starting time.");
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->max_meals == 0)
		return (NULL);
	if (philo->table->nb_ph == 1)
		solo_philo_routine(philo);
	else
	{
		while (philo->table->feast_end)
		{
			if (philo->id % 2 == 0)
				usleep(200);
			eat_routine(philo);
			sleep_routine(philo);
			think_routine(philo);
		}
	}
	return (NULL);
}

void	*obs_thread(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
}

void	assign_forks(t_table *table)
{
	int	i;

	i = 0;
	if (table->nb_ph < 2)
	{
		table->philos[0]->fork_l = &table->forks[0];
		table->philos[0]->fork_r = &table->forks[0];
	}
	else
	{
		while (i < table->nb_ph - 1)
		{
			table->philos[i]->fork_l = &table->forks[i];
			table->philos[i]->fork_r = &table->forks[i + 1];
			i++;
		}
		table->philos[i]->fork_l = &table->forks[i];
		table->philos[i]->fork_r = &table->forks[0];
	}
}

void	start_meal(t_table *table)
{
	int	i;

	i = 0;
	assign_forks(table);
	start_timer(table);
	while (table->philos[i])
	{
		if (pthread_create(table->philos[i]->tid, NULL, &philo_thread, 
			(void *)table->philos[i]))
			error_table(table, "error creating philo thread.");
		i++;
	}
	if (pthread_create(table->tid_obs, NULL, &obs_thread, (void *)table))
		error_table(table, "error creating obs thread.");
}