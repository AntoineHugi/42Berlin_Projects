/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:34 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/04 12:31:35 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_input(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(1);
}

void	error_map(char *str, t_map *map)
{
	int	i;

	i = 0;
	ft_printf("Error: %s\n", str);
	while (map->map_array[i])
		free(map->map_array[i++]);
	free(map->map_array);
	free(map->map_path_check);
	free(map);
	exit(1);
}