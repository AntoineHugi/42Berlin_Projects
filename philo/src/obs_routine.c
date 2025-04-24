#include "../includes/philo.h"

int	meal_stops(t_table *table)
{
	int		i;
	int		end_check;
	time_t	now;

	i = 0;
	end_check = 0;
	get_time(&now, table);
	while (i < table->nb_ph)
	{
		if (now - table->philos[i]->last_meal > table->ttd)
		{
			print_action('d', table->philos[i]);
			return (1);
		}
		if (table->philos[i++]->times_eaten >= table->max_meals
			&& table->max_meals >= 0)
			end_check = 1;
		else
			end_check = 0;
		i++;
	}
	if (end_check)
		return (1);
	return (0);
}
