#include "../includes/philo.h"

free_philos(t_philo **philos)
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
	free(table);
}