/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:45:34 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/10 14:45:36 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
void	my_mlx_pixel_put(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = 0;
}

void	black_screen(t_map *map)
{
	int		x;
	int		y;
	
	x = 0;
	while (x < map->win_x)
	{
		y = 0;
		while(y < map->win_y)
		{
			my_mlx_pixel_put(map->img, x, y);
			y++;
		}
		x++;
	}
}*/

static t_sprite	new_sprite(void *mlx, char *path, t_map *map)
{
	t_sprite	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error_map("Couldn't find a sprite file.", map);
	return (sprite);
}

static void	init_sprites(t_map *map)
{
	map->chicken = new_sprite(map->mlx, CHICKEN_XPM, map);
	map->player = new_sprite(map->mlx, PLAYER_XPM, map);
	map->wall = new_sprite(map->mlx, WALL_XPM, map);
	map->floor = new_sprite(map->mlx, FLOOR_XPM, map);
	map->exit = new_sprite(map->mlx, EXIT_XPM, map);
	map->won = new_sprite(map->mlx, WIN_XPM, map);
}

void	init_game(t_map *map)
{
	init_sprites(map);
}
