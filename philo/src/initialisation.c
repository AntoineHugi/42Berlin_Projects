#include "../includes/philo.h"

static pthread_mutex_t	*init_forks(t_table *table)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->nb_ph);
	if (!forks)
		return (NULL);
	while (i < table->nb_ph)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (NULL);
		i++;
	}
	return (forks);
}

static int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->print_lock, NULL))
		return (0);
	if (pthread_mutex_init(&table->death_lock, NULL))
		return (0);
	if (pthread_mutex_init(&table->meal_end_lock, NULL))
		return (0);
	table->forks = init_forks(table);
	if (!table->forks)
		return (0);
	return (1);
}

static t_philo	*init_philo(t_table *table)
{
	t_philo	*philo;
	time_t	now;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	get_time(&now, table);
	philo->times_eaten = 0;
	philo->last_meal = now;
	philo->tid = 0;
	philo->table = table;
	return (philo);
}

static int	init_philos(t_table *table)
{
	int		i;

	i = 0;
	table->philos = (t_philo **)malloc(table->nb_ph * sizeof(t_philo *));
	if (!table->philos)
		return (0);
	while (i < table->nb_ph)
	{
		table->philos[i] = init_philo(table);
		table->philos[i]->id = i + 1;
		if (!table->philos[i])
			return (0);
		if (i % 2 == 0)
			table->philos[i]->ttt = table->tts;
		else
			table->philos[i]->ttt = table->tts / 2;
		i++;
	}
	return (1);
}

t_table	*init_table(char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nb_ph = (int)ft_atoll(argv[1]);
	table->meal_end = 0;
	table->max_meals = -1;
	table->ttd = (int)ft_atoll(argv[2]);
	table->tte = (int)ft_atoll(argv[3]);
	table->tts = (int)ft_atoll(argv[4]);
	if (argv[5])
		table->max_meals = (int)ft_atoll(argv[5]);
	if (!init_mutex(table))
		return (NULL);
	if (!init_philos(table))
		return (NULL);
	return (table);
}
