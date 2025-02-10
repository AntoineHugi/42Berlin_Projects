/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:43:53 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/10 14:43:55 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_img(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_array[i])
	{
		free(map->map_array[i]);
		free(map->map_path_check[i]);
		free(map->map_reset[i]);
		i++;
	}
	free(map->map_array);
	free(map->map_path_check);
	free(map->map_reset);
	mlx_destroy_image(map->mlx, map->chicken.xpm_ptr);
	mlx_destroy_image(map->mlx, map->player.xpm_ptr);
	mlx_destroy_image(map->mlx, map->exit.xpm_ptr);
	mlx_destroy_image(map->mlx, map->wall.xpm_ptr);
	mlx_destroy_image(map->mlx, map->floor.xpm_ptr);
	mlx_destroy_image(map->mlx, map->won.xpm_ptr);
}

void	free_map(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free(map);
}
