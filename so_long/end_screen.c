/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:01:25 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/04 12:31:29 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_app(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_array[i])
	{
		free(map->map_array[i]);
		free(map->map_path_check[i]);
		i++;
	}
	free(map->map_array);
	free(map->map_path_check);
	mlx_destroy_image(map->mlx, map->chicken.xpm_ptr);
	mlx_destroy_image(map->mlx, map->player.xpm_ptr);
	mlx_destroy_image(map->mlx, map->exit.xpm_ptr);
	mlx_destroy_image(map->mlx, map->wall.xpm_ptr);
	mlx_destroy_image(map->mlx, map->floor.xpm_ptr);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free(map);
	exit(1);
}

void	game_won(t_map *map)
{
	map->moves++;
}