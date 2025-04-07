#include "../includes/philo.h"

void	free_mutex(t_table *table)
{
	int i;

	i= 0;
	pthread_mutex_destroy(&table->death_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->feast_end_lock);
	while (i < table->philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}

void	free_philos(t_philo **philos)
{
	int i;

	i= 0;
	while (philos[i])
	{
		free(philos[i]);
		i++;
	}
	free(philos);
}

void	free_table(t_table *table)
{
	free_philos(table->philos);
	free_mutex(table);
	free(table);
}