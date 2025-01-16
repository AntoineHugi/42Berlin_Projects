/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:01:25 by ahugi             #+#    #+#             */
/*   Updated: 2025/01/14 15:02:09 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		xaxis;
	int		yaxis;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 540, "./so_long");
	img.img = mlx_new_image(vars.mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	xaxis = 10;
	yaxis = 10;
	while (xaxis < 51)
	{
		my_mlx_pixel_put(&img, xaxis, yaxis, 0x00FF0000);
		xaxis++;
	}
	xaxis = 10;
	while (xaxis < 140)
	{
		if (xaxis < 31)
			my_mlx_pixel_put(&img, xaxis, xaxis, 0x00FF0000);
		else
			my_mlx_pixel_put(&img, xaxis, 141 - xaxis, 0x00FF0000);
		xaxis++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_loop(mlx);

	mlx_destroy_image(vars.mlx, img.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
