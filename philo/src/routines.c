#include "../includes/philo.h"

void	solo_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_action(fork);
	think_routine(philo, philo->ttd);
	print_action('d', philo);
	pthread_mutex_unlock(philo->fork_l);
}

void	eat_routine(t_philo *philo)
{

}

void	sleep_routine(t_philo *philo)
{

}

void	think_routine(t_philo *philo, time_t duration)
{

}