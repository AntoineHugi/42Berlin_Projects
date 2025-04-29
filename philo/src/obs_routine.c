#include "../includes/philo.h"

static void	end_meal(t_table *table)
{
	pthread_mutex_lock(&(table->meal_end_lock));
	table->meal_end = 1;
	pthread_mutex_unlock(&(table->meal_end_lock));
}

static int	food_coma_check(t_table *table, int i)
{
	pthread_mutex_lock(&(table->food_coma_lock));
	if (table->times_eaten[i] >= table->max_meals)
	{
		pthread_mutex_unlock(&(table->food_coma_lock));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(table->food_coma_lock));
		return (0);
	}
}

static int	death_check(t_philo *philo)
{
	time_t	now;

	get_time(&now, philo->table);
	pthread_mutex_lock(&(philo->meal_time_lock));
	if (now - philo->last_meal > philo->table->ttd)
	{
		pthread_mutex_unlock(&(philo->meal_time_lock));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(philo->meal_time_lock));
		return (0);
	}

}

static int	meal_stops(t_table *table)
{
	int		i;
	int		end_check;

	i = 0;
	end_check = 0;
	while (i < table->nb_ph)
	{
		if (death_check(table->philos[i]))
		{
			print_action('d', table->philos[i]);
			end_meal(table);
			return (1);
		}
		if (food_coma_check(table, i))
			end_check = 1;
		else
			end_check = 0;
		i++;
	}
	if (end_check)
		return (1);
	return (0);
}

void	*obs_thread(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (meal_stops(table))
			break ;
		usleep(100);
	}
	end_meal(table);
	return (NULL);
}
