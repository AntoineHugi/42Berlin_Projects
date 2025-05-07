#include "main.h"

void	print_set(int *working_set, int working_set_len)
{
	int	i = 0;
	while (i < working_set_len - 1)
	{
		printf("%i,", working_set[i]);
		i++;
	}
	printf("%i", working_set[i]);
	printf("\n");
}

void	check_sum(int start, int *set, int target, int set_size, int *working_set, int working_set_len)
{
	int i;

	if (target == 0)
	{
		//check_for_extra_zero
		print_set(working_set, working_set_len);
	}
	if (target < 0 || start == set_size)
		return;
	working_set[working_set_len] = set[start];
	i = start;
	check_sum(start + 1, set, target - set[start], set_size, working_set, working_set_len + 1);
	check_sum(start + 1, set, target, set_size, working_set, working_set_len);
}

void	powerset(void)
{
	int		target;
	int		set_size;
	int 	set[6] = {4, 7, 12, 23, 43, 23};

	set_size = sizeof(set)/sizeof(set[0]);
	int		working_set[set_size];
	target = 66;
	check_sum(0, set, target, set_size, working_set, 0);
}