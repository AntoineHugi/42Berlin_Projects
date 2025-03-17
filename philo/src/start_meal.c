#include "../includes/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

}

void	*obs_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
}

void	start_meal(t_table *table)
{
	int	i;

	i = 0;
	while (table->philos[i])
	{
		if (pthread_create(table->philos[i]->tid, NULL, &philo_routine, 
			(void *)table->philos[i]))
			error_table(table, "error creating philo thread.");
		i++;
	}
	if (pthread_create(table->tid_obs, NULL, &obs_routine, 
		(void *)table))
		error_table(table, "error creating obs thread.");
}