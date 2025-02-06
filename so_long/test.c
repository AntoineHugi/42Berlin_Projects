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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	coloring(t_img *img, int x, int y, int color)
{
	int	xaxis;
	int	yaxis;
	
	xaxis = 0;
	while (xaxis < x)
	{
		yaxis = 0;
		while(yaxis < y)
		{
			if (xaxis < 5 || yaxis < 5)
				my_mlx_pixel_put(img, xaxis, yaxis, 0x00000000);
			else
				my_mlx_pixel_put(img, xaxis, yaxis, color);
			yaxis++;
		}
		xaxis++;
	}
}

int	rainbow(t_game *game)
{
	unsigned char t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int	trgb;
	unsigned char temp;
	usleep(500000);
	t = get_t(game->color);
	r = get_r(game->color);
	g = get_g(game->color);
	b = get_b(game->color);
	if (b <= g)
	{
		if (g <= r)
		{
			temp = r;
			r = b;
			b = temp;
		}
		else
		{
			temp = g;
			g = r;
			r = temp;
		}
	}
	else
	{
		temp = b;
		b = g;
		g = temp;
	}
	trgb = create_trgb(t,r,g,b);
	game->color = trgb;
	coloring(game->img, WIN_W, WIN_H, game->color);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return(0);
}

int	exit_app(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map_array[i])
	{
		free(game->map->map_array[i]);
		free(game->map->map_path_check[i]);
		i++;
	}
	free(game->map->map_array);
	free(game->map->map_path_check);
	free(game->map);
	mlx_destroy_image(game->mlx, game->img->img);
	mlx_destroy_image(game->mlx, game->chicken.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit.xpm_ptr);
	mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	render_sprite(t_game *game, t_sprite sprite, int height, int width)
{
	mlx_put_image_to_window (game->mlx, game->win, \
	sprite.xpm_ptr, width * sprite.y, height * sprite.x);
}

void	render_tile(t_game *game, int height, int width)
{
	if (game->map->map_array[height][width] == '1')
		render_sprite(game, game->wall, height, width);
	if (game->map->map_array[height][width] == '0')
		render_sprite(game, game->floor, height, width);
	if (game->map->map_array[height][width] == 'P')
		render_sprite(game, game->player, height, width);
	if (game->map->map_array[height][width] == 'C')
		render_sprite(game, game->chicken, height, width);
	if (game->map->map_array[height][width] == 'E')
		render_sprite(game, game->exit, height, width);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->map->tile_w = (WIN_W - 100)/game->map->width;
	game->map->tile_h = WIN_H - 100/game->map->height;

	while (x < game->map->height)
	{
		y = 0;
		while (y < game->map->width)
		{
			render_tile(game, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	img;
	t_map	*map;

	if (input_validation(argc, argv))
	{
		map = map_creation(argv[1]);
		if (!map)
			error_input("failed to open file");
		if (map_validation(map))
		{
			ft_printf("it's valid!\n");
			game.map = map;
		}
	}
	game.color = 0x00FF0000;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_W, WIN_H, "./so_long");
	img.img = mlx_new_image(game.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	game.img = &img;
	//mlx_put_image_to_window(game.mlx, game.win, game.img->img, 0, 0);
	init_game(&game);
//	render_map(&game);

	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0L, exit_app, &game);
	mlx_loop_hook(game.mlx, render_map, &game);
	mlx_loop(game.mlx);
	return (argc);
}
