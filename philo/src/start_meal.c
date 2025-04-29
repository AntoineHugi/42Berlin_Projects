#include "../includes/philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->max_meals == 0)
		return (NULL);
	if (philo->table->nb_ph == 1)
		solo_philo_routine(philo);
	else
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		multi_philo_routine(philo);
	}
	return (NULL);
}



static void	assign_forks(t_table *table)
{
	int	i;

	i = 0;
	if (table->nb_ph < 2)
	{
		table->philos[0]->fork_l = table->forks[0];
		table->philos[0]->fork_r = table->forks[0];
	}
	else
	{
		while (i < table->nb_ph - 1)
		{
			table->philos[i]->fork_l = table->forks[i];
			table->philos[i]->fork_r = table->forks[i + 1];
			i++;
		}
		table->philos[i]->fork_l = table->forks[i];
		table->philos[i]->fork_r = table->forks[0];
	}
}

void	start_meal(t_table *table)
{
	int	i;

	i = 0;
	assign_forks(table);
	get_time(&(table->start), table);
	while (i < table->nb_ph)
	{
		if (pthread_create(&table->philos[i]->tid, NULL, &philo_thread,
				(void *)table->philos[i]))
			error_table(table, "error creating philo thread.");
		i++;
	}
	if (table->nb_ph > 1)
	{
		if (pthread_create(&table->tid_obs, NULL, &obs_thread, (void *)table))
			error_table(table, "error creating obs thread.");
		pthread_join(table->tid_obs, NULL);
	}
	i = 0;
	while (i < table->nb_ph)
	{
		pthread_join(table->philos[i]->tid, NULL);
		i++;
	}
	free_table(table);
}
