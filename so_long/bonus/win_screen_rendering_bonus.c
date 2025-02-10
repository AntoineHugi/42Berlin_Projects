/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_screen_rendering_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:11:24 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/10 15:11:28 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_win_screen(t_map *map)
{
	int	x;
	int	y;

	x = map->win_x / 4;
	y = map->win_y / 2;
	if (!map->win_clear)
	{
		mlx_clear_window(map->mlx, map->win);
		map->win_clear = 1;
	}
	mlx_string_put(map->mlx, map->win, x, y, RED, 
		"Press R to restart or Esc to quit.");
	render_sprite(map, map->won, 0, map->width / 1.2);
}
