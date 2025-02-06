#include "so_long.h"

static t_sprite	new_sprite(void *mlx, char *path, t_game *game)
{
	t_sprite	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error_map("Couldn't find a sprite. Does it exist?", game->map);
	return (sprite);
}

static void	init_sprites(t_game *game)
{
	game->chicken = new_sprite(game->mlx, CHICKEN_XPM, game);
	game->player = new_sprite(game->mlx, PLAYER_XPM, game);
	game->wall = new_sprite(game->mlx, WALL_XPM, game);
	game->floor = new_sprite(game->mlx, FLOOR_XPM, game);
	game->exit = new_sprite(game->mlx, EXIT_XPM, game);
}

void	init_game(t_game *game)
{
	init_sprites(game);
}
