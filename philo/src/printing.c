#include "../includes/philo.h"

static void	write_action(char a, t_philo *philo)
{
	time_t	time;

	get_time(&time, philo->table);
	time = time - philo->table->start;
	if (a == 'f')
		printf("%ld %i has taken a fork\n", time, philo->id);
	else if (a == 'e')
		printf("%ld %i is eating\n", time, philo->id);
	else if (a == 's')
		printf("%ld %i is sleeping\n", time, philo->id);
	else if (a == 't')
		printf("%ld %i is thinking\n", time, philo->id);
	else if (a == 'd')
		printf("%ld %i died \n", time, philo->id);
}

void	print_action(char a, t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->print_lock));
	if (!philo->table->meal_end)
		write_action(a, philo);
	pthread_mutex_unlock(&(philo->table->print_lock));
}
