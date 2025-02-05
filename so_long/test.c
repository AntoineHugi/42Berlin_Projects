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

int	rainbow(t_vars *vars)
{
	unsigned char t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int	trgb;
	unsigned char temp;
	usleep(500000);
	t = get_t(vars->color);
	r = get_r(vars->color);
	g = get_g(vars->color);
	b = get_b(vars->color);
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
	vars->color = trgb;
	coloring(vars->img, WIN_W, WIN_H, vars->color);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return(0);
}

int	exit_app(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map->map_array[i])
	{
		free(vars->map->map_array[i]);
		free(vars->map->map_path_check[i]);
		i++;
	}
	free(vars->map->map_array);
	free(vars->map->map_path_check);
	free(vars->map);
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
}

int	resize(t_vars *vars)
{
	ft_printf("Resized.\n");
	ft_printf("\n%p\n", vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		exit_app(vars);
	ft_printf("The keycode is %i!\n", keycode);
	ft_printf("\n%p\n", vars->win);
	return (0);
}

//not working
/*
void	render_map(t_vars *vars)
{
	int	tile_w;
	int	tile_h;
	int	i;
	int	j;

	i = 1;
	tile_w = (WIN_W - 100)/vars->map->width;
	tile_h = WIN_H/vars->map->height;

	while (i <= vars->map->height)
	{
		j = 1;
		while (j <= vars->map->width)
		{
			if (i * tile_h < 5 || yaxis < 5)
				my_mlx_pixel_put(vars->img, xaxis, yaxis, 0x00000000);
			else
				my_mlx_pixel_put(vars->img, xaxis, yaxis, 0x00FF0000);
			yaxis++;
			j++;
		}
		i++;
	}

	//ft_printf("tile width is: %i, tile heigth is: %i\n", tile_w, tile_h);
}/*

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_img	img;
	t_map	*map;

	if (input_validation(argc, argv))
	{
		map = map_creation(argv[1]);
		if (!map)
		{
			free(map);
			error_input("failed to open file");
		}
		ft_printf("width is : %i, height is : %i\n", map->width, map->height);
		if (map_validation(map))
		{
			ft_printf("it's valid!\n");
			vars.map = map;
		}
	}
	vars.color = 0x00FF0000;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "./so_long");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	vars.img = &img;
	render_map(&vars);
	//coloring(vars.img, WIN_W, WIN_H, vars.color);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, exit_app, &vars);
	mlx_hook(vars.win, 25, 0L, resize, &vars);
	//mlx_loop_hook(vars.mlx, rainbow, &vars);
	mlx_loop(vars.mlx);
	return (argc);
}
