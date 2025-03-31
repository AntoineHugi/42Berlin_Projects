#include "../includes/philo.h"
/* figure out how to cycle through fork mutexes */
void	free_mutex(t_table *table)
{
	int i;

	i= 0;
	pthread_mutex_destroy(&table->death);
	pthread_mutex_destroy(&table->print);
	while (table->fork[i] != 0)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	free(table->fork);
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