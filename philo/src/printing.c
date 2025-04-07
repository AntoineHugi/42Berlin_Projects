#include "../includes/philo.h"

void	write_action(char a, t_philo *philo)
{
	time_t	time;

	time = get_time() - philo->table->start;
	if (a == 'f')
		printf("%ld %i has taken a fork", time, philo->id);
	else if (a == 'e')
		printf("%ld %i has eaten", time, philo->id);
	else if (a == 's')
		printf("%ld %i is sleeping", time, philo->id);
	else if (a == 't')
		printf("%ld %i is thinking", time, philo->id);
	else if (a == 'd')
		printf("%ld %i has died", time, philo->id);
}

void	print_action(char a, t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->print_lock));
	write_action(a, philo);
	pthread_mutex_unlock(&(philo->table->print_lock));
}
