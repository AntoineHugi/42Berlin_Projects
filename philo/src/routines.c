#include "../includes/philo.h"

void	solo_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_action('f', philo);
	think_routine(philo, philo->table->ttd);
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
	get_time(&(philo->last_meal), philo->table);
	usleep(philo->table->tte * 1000);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

void	sleep_routine(t_philo *philo)
{
	print_action('s', philo);
	usleep(philo->table->tts * 1000);
}

void	think_routine(t_philo *philo, time_t duration)
{
	print_action('t', philo);
	usleep(duration * 1000);
}