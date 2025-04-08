#include "../includes/philo.h"

void	solo_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_action('f', philo);
	think_routine(philo, philo->ttd);
	print_action('d', philo);
	pthread_mutex_unlock(philo->fork_l);
}

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_action('f', philo);
	pthread_mutex_lock(philo->fork_r);
	print_action('f', philo);
	print_action('e', philo);
	usleep(philo->tte * 1000);
	gettimeofday(philo->last_meal, NULL);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

void	sleep_routine(t_philo *philo)
{
	print_action('s', philo);
	usleep(philo->tts * 1000);
}

void	think_routine(t_philo *philo, time_t duration)
{
	print_action('t', philo);
	usleep(duration * 1000);
}