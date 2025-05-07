#include "main.h"

float coords[5][2] = 
{
	{0, 0},
	{2, 2},
	{123, 234},
	{234, 56},
	{34, 78},
};
    
float distance(int a, int b) 
{
	float dx = coords[a][0] - coords[b][0];
	float dy = coords[a][1] - coords[b][1];
	return (sqrt(dx * dx + dy * dy));
}

void swap(int *a, int *b) 
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

float	calculate_route_len(int *cities, int total)
{
	float	len;
	int	i;

	i = 0;
	len = 0;
	while (i < total - 1)
	{
		len = len + distance(cities[i], cities[i + 1]);
		i++;
	}
	len = len + distance(cities[i], cities[0]);
	return (len);
}

void	generate_best_route(int *cities, int start, int total, float *min_dist)
{
	float	len;
	int	i;

	if (start == total - 1)
	{
		len = calculate_route_len(cities, total);
		if (*min_dist > len)
			*min_dist = len;
		return ;
	}
	i = start;
	while (i < total)
	{
		swap(&cities[start], &cities[i]);
		generate_best_route(cities, start + 1, total, min_dist);
		swap(&cities[start], &cities[i]);
		i++;
	}
}

void	tsp(void)
{
	int cities[5] = {0, 1, 2, 3, 4};
	float min_dist = 1e9;

	generate_best_route(cities, 0, 5, &min_dist);
	printf("tsp min dist = %.2f\n", min_dist);
}
