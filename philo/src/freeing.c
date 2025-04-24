#include "../includes/philo.h"

void	free_mutex(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->death_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->meal_end_lock);
	i = 0;
	while (i < table->nb_ph)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}

void	free_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_ph)
	{
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
}

void	free_table(t_table *table)
{
	free_philos(table);
	free_mutex(table);
	free(table);
}
