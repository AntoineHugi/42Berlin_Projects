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
}

void	*obs_thread(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
}

void	start_meal(t_table *table)
{
	int	i;

	i = 0;
	start_timer(table);
	while (table->philos[i])
	{
		if (pthread_create(table->philos[i]->tid, NULL, &philo_thread, 
			(void *)table->philos[i]))
			error_table(table, "error creating philo thread.");
		i++;
	}
	if (pthread_create(table->tid_obs, NULL, &obs_thread, 
		(void *)table))
		error_table(table, "error creating obs thread.");
}