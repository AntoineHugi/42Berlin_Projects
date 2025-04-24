#include "../includes/philo.h"

static void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	if (philo->table->meal_end)
	{
		pthread_mutex_unlock(philo->fork_l);
		return ;
	}
	print_action('f', philo);
	pthread_mutex_lock(philo->fork_r);
	if (philo->table->meal_end)
	{
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		return ;
	}
	print_action('f', philo);
	print_action('e', philo);
	get_time(&(philo->last_meal), philo->table);
	usleep(philo->table->tte * 1000);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

static void	sleep_routine(t_philo *philo)
{
	print_action('s', philo);
	usleep(philo->table->tts * 1000);
}

static void	think_routine(t_philo *philo)
{
	print_action('t', philo);
	usleep(philo->ttt * 1000);
}

void	multi_philo_routine(t_philo *philo)
{
	while (!philo->table->meal_end)
	{
		if (!philo->table->meal_end)
			eat_routine(philo);
		if (!philo->table->meal_end)
			sleep_routine(philo);
		if (!philo->table->meal_end)
			think_routine(philo);
	}
}

void	solo_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_action('f', philo);
	usleep(philo->table->ttd * 1000);
	print_action('d', philo);
	pthread_mutex_unlock(philo->fork_l);
}
