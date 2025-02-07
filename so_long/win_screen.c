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
/*
void	draw_end(t_map *map)
{
	int	x;
	int	y;
	
	x = PIX * map->width + 100;
	y = PIX * map->height;
}
*/
void	game_won(t_map *map)
{
	map->moves++;
	ft_printf("congratulations, you won with %i moves!\n", map->moves);
	exit_app(map);
/*	
	End screen maybe, using win_sprite
	mlx_clear_window(map->mlx, map->win);
	mlx_string_put(map->mlx, map->win, x, y, 255, "YOU WIN!");
	mlx_hook(map->win, 17, 0L, exit_app, map);
	mlx_loop(map->mlx);*/
}