#include "so_long.h"

static t_sprite	new_sprite(void *mlx, char *path, t_map *map)
{
	t_sprite	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error_map("Couldn't find a sprite. Does it exist?", map);
	return (sprite);
}

static void	init_sprites(t_map *map)
{
	map->chicken = new_sprite(map->mlx, CHICKEN_XPM, map);
	map->player = new_sprite(map->mlx, PLAYER_XPM, map);
	map->wall = new_sprite(map->mlx, WALL_XPM, map);
	map->floor = new_sprite(map->mlx, FLOOR_XPM, map);
	map->exit = new_sprite(map->mlx, EXIT_XPM, map);
}

void	init_game(t_map *map)
{
	init_sprites(map);
}
