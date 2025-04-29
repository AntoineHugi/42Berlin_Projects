#include "../includes/philo.h"

int	meal_end_check(t_table *table)
{
	pthread_mutex_lock(&(table->meal_end_lock));
	if (table->meal_end)
	{
		pthread_mutex_unlock(&(table->meal_end_lock));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(table->meal_end_lock));
		return (0);
	}
}

static void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	if (meal_end_check(philo->table))
	{
		pthread_mutex_unlock(&(philo->fork_l));
		return ;
	}
	print_action('f', philo);
	pthread_mutex_lock(&(philo->fork_r));
	if (meal_end_check(philo->table))
	{
		pthread_mutex_unlock(&(philo->fork_l));
		pthread_mutex_unlock(&(philo->fork_r));
		return ;
	}
	print_action('f', philo);
	print_action('e', philo);
	usleep(philo->table->tte * 1000);
	pthread_mutex_unlock(&(philo->fork_l));
	pthread_mutex_unlock(&(philo->fork_r));
	pthread_mutex_lock(&(philo->meal_time_lock));
	get_time(&(philo->last_meal), philo->table);
	pthread_mutex_unlock(&(philo->meal_time_lock));
	pthread_mutex_lock(&(philo->table->food_coma_lock));
		philo->table->times_eaten[philo->id - 1]++;
	pthread_mutex_unlock(&(philo->table->food_coma_lock));
}

static void	sleep_think_routine(t_philo *philo)
{
	if (!meal_end_check(philo->table))
		print_action('s', philo);
	usleep(philo->table->tts * 1000);
	if (!meal_end_check(philo->table))
		print_action('t', philo);
}

void	multi_philo_routine(t_philo *philo)
{
	while (1)
	{
		eat_routine(philo);
		sleep_think_routine(philo);
		if (meal_end_check(philo->table))
			break ;
	}
}

void	solo_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	print_action('f', philo);
	usleep(philo->table->ttd * 1000);
	print_action('d', philo);
	pthread_mutex_unlock(&(philo->fork_l));
}
