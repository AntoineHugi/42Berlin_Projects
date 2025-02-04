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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	coloring(t_data *data, int x, int y, int color)
{
	int	xaxis;
	int	yaxis;
	
	xaxis = 0;
	while (xaxis < x)
	{
		yaxis = 0;
		while(yaxis < y)
		{
			my_mlx_pixel_put(data, xaxis, yaxis, color);
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
	if (ft_isdigit(t))
		vars->color = trgb;
	coloring(vars->img, 960, 540, vars->color);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return(0);
}

int	exit_app(t_vars *vars)
{
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
	//int	trgb;
	
	if (keycode == 65307)
		exit_app(vars);
	ft_printf("The keycode is %i!\n", keycode);
	ft_printf("\n%p\n", vars->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int	i;
	
	i = 0;
	if (input_validation(argc, argv))
	{
		map = map_creation(argv[1]);
		if (!map)
		{
			free(map);
			error_input("failed to open file");
		}
		ft_printf("height is : %i, width is : %i\n", map->height, map->width);
		if (map_validation(map))
			ft_printf("it's valid!");
		while (map->map_array[i])
			free(map->map_array[i++]);
		free(map->map_array);
		free(map->map_path_check);
		free(map);
	}
	return (1);
	
	
	
	/*vars	vars;
	t_data	img;

	vars.color = 0x00FF0000;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 540, "./so_long");
	img.img = mlx_new_image(vars.mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	vars.img = &img;
	coloring(vars.img, 960, 540, vars.color);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, exit_app, &vars);
	mlx_hook(vars.win, 25, 0L, resize, &vars);
	mlx_loop_hook(vars.mlx, rainbow, &vars);
	mlx_loop(vars.mlx);*/
}
