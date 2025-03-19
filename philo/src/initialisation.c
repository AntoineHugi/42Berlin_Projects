#include "../includes/philo.h"

static t_philo	*init_philo(char **argv)
{
	t_philo	*philo;

	philo = (t_philo*)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->ttd = (int)ft_atoll(argv[2]);
	philo->tte = (int)ft_atoll(argv[3]);
	philo->tts = (int)ft_atoll(argv[4]);
	philo->is_dead = 0;
	philo->times_eaten = 0;
}

static int	init_philos(t_table *table, char **argv)
{
	int		i;

	i = 0;
	table->philos=(t_philo**)malloc((ft_atoll(argv[1]) + 1) * sizeof(t_philo*));
	if (!table->philos)
		return(NULL);
	while (i < (int)ft_atoll(argv[1]))
	{
		table->philos[i] = init_philo(**argv);
		if (!table->philos[i])
			return (NULL);
		if (i % 2 == 0)
			table->philos[i]->ttt = table->philos[i]->tts;
		else
			table->philos[i]->ttt = table->philos[i]->tts/2;
		i++;
	}
	return (1);
}
/* need to init mutexes as well */
t_table	*init_table(char **argv)
{
	t_table	*table;


	table = (t_table*)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	if (!init_philos(table, argv))
		return (NULL);
	return (table);
}