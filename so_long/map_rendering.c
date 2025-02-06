#include "so_long.h"

void	render_sprite(t_map *map, t_sprite sprite, int height, int width)
{
	mlx_put_image_to_window (map->mlx, map->win, \
	sprite.xpm_ptr, width * sprite.y, height * sprite.x);
}

void	render_tile(t_map *map, int height, int width)
{
	if (map->map_array[height][width] == '1')
		render_sprite(map, map->wall, height, width);
	if (map->map_array[height][width] == '0')
		render_sprite(map, map->floor, height, width);
	if (map->map_array[height][width] == 'P')
		render_sprite(map, map->player, height, width);
	if (map->map_array[height][width] == 'C')
		render_sprite(map, map->chicken, height, width);
	if (map->map_array[height][width] == 'E')
		render_sprite(map, map->exit, height, width);
}

int	render_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			render_tile(map, x, y);
			y++;
		}
		x++;
	}
	return (0);
}