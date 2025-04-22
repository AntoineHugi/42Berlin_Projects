#include "../includes/philo.h"

void	error_arguments()
{
	printf("Invalid arguments, please provide 4 or 5 arguments:\n");
	printf("Number of philosophers (at least 1, but less than 200)\n");
	printf("Time until death (in ms), time to eat (in ms), ");
	printf("time to sleep (in ms)\n");
	printf("(optional) Number of times each philo should have ");
	printf("eaten to end the meal.\n");
	printf("Example: 5 800 200 200 3\n");
	exit(1);
}

void	error_table(t_table *table, char *msg)
{
	free_table(table);
	printf("%s\n", msg);
	exit(1);
}
