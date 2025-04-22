#include "../includes/philo.h"

void	end_meal(t_table *table)
{
	pthread_mutex_lock(&(table->meal_end_lock));
	table->meal_end = 1;
	pthread_mutex_unlock(&(table->meal_end_lock));
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->max_meals == 0)
		return (NULL);
	if (philo->table->nb_ph == 1)
		solo_philo_routine(philo);
	else
	{
		while (!philo->table->meal_end)
		{
			if (philo->id % 2 == 0)
				usleep(1000);
			eat_routine(philo);
			sleep_routine(philo);
			think_routine(philo, philo->ttt);
		}
	}
	return (NULL);
}

void	*obs_thread(void *arg)
{
	t_table	*table;
	int	i;
	int	end_check;
	time_t	now;

	table = (t_table *)arg;
	while (!table->meal_end)
	{
		i = 0;
		end_check = 0;
		while (i < table->nb_ph)
		{
			get_time(&now, table);
			if (now - table->philos[i]->last_meal > table->ttd)
			{
				print_action('d', table->philos[i]);
				end_check = 1;
				break ;
			}
			if (table->philos[i]->times_eaten >= table->max_meals &&
				table->max_meals >= 0)
				end_check = 1;
			else
				end_check = 0;
			i++;
		}
		if (end_check)
		{
			printf("meal ends. they ate %i times\n", table->philos[4]->times_eaten);
			break ;
		}
	}
	end_meal(table);
	return (NULL);
}

static void	assign_forks(t_table *table)
{
	int	i;

	i = 0;
	if (table->nb_ph < 2)
	{
		table->philos[0]->fork_l = &table->forks[0];
		table->philos[0]->fork_r = &table->forks[0];
	}
	else
	{
		while (i < table->nb_ph - 1)
		{
			table->philos[i]->fork_l = &table->forks[i];
			table->philos[i]->fork_r = &table->forks[i + 1];
			i++;
		}
		table->philos[i]->fork_l = &table->forks[i];
		table->philos[i]->fork_r = &table->forks[0];
	}
}

void	start_meal(t_table *table)
{
	int	i;

	i = 0;
	assign_forks(table);
	get_time(&(table->start), table);
	while (i < table->nb_ph)
	{
		if (pthread_create(&table->philos[i]->tid, NULL, &philo_thread, 
			(void *)table->philos[i]))
			error_table(table, "error creating philo thread.");
		i++;
	}
	if (pthread_create(&table->tid_obs, NULL, &obs_thread, (void *)table))
		error_table(table, "error creating obs thread.");
	pthread_join(table->tid_obs, NULL);
	i = 0;
	while (i < table->nb_ph)
	{
		pthread_join(table->philos[i]->tid, NULL);
		i++;
	}
}
