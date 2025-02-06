#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->map_array[map->p_pos[0] - 1][map->p_pos[1]] != '1')
	{
		if (map->map_array[map->p_pos[0] - 1][map->p_pos[1]] == 'C')
			map->collect_count--;
		//if (map->map_array[map->p_pos[0] - 1][map->p_pos[1]] == 'E'
			//&& map->collect_count != 0)
			//game_won();
		map->map_array[map->p_pos[0] - 1][map->p_pos[1]] = 'P';
		if (map->p_pos[0] == map->e_pos[0] && map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else	
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[0]--;
	}
}

void	move_down(t_map *map)
{
	if (map->map_array[map->p_pos[0] + 1][map->p_pos[1]] != '1')
	{
		if (map->map_array[map->p_pos[0] + 1][map->p_pos[1]] == 'C')
			map->collect_count--;
		//if (map->map_array[map->p_pos[0] + 1][map->p_pos[1]] == 'E'
			//&& map->collect_count != 0)
			//game_won();
		map->map_array[map->p_pos[0] + 1][map->p_pos[1]] = 'P';
		if (map->p_pos[0] == map->e_pos[0] && map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else	
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[0]++;
	}
}

void	move_right(t_map *map)
{
	if (map->map_array[map->p_pos[0]][map->p_pos[1] + 1] != '1')
	{
		if (map->map_array[map->p_pos[0]][map->p_pos[1] + 1] == 'C')
			map->collect_count--;
		//if (map->map_array[map->p_pos[0]][map->p_pos[1] + 1] == 'E'
			//&& map->collect_count != 0)
			//game_won();
		map->map_array[map->p_pos[0]][map->p_pos[1] + 1] = 'P';
		if (map->p_pos[0] == map->e_pos[0] && map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else	
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[1]++;
	}
}

void	move_left(t_map *map)
{
	if (map->map_array[map->p_pos[0]][map->p_pos[1] - 1] != '1')
	{
		if (map->map_array[map->p_pos[0]][map->p_pos[1] - 1] == 'C')
			map->collect_count--;
		//if (map->map_array[map->p_pos[0]][map->p_pos[1] - 1] == 'E'
			//&& map->collect_count != 0)
			//game_won();
		map->map_array[map->p_pos[0]][map->p_pos[1] - 1] = 'P';
		if (map->p_pos[0] == map->e_pos[0] 
			&& map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else	
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[1]--;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_app(game);
	if (keycode == 65362 || keycode == 119)
		move_up(game->map);
	if (keycode == 65364 || keycode == 115)
		move_down(game->map);
	if (keycode == 65363 || keycode == 100)
		move_right(game->map);
	if (keycode == 65361 || keycode == 97)
		move_left(game->map);
	if (keycode == 114)
		init_game(game);
	ft_printf("The keycode is %i!\n", keycode);
	ft_printf("\n%p\n", game->win);
	return (0);
}