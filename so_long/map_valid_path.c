#include "so_long.h"

int     targets_left(t_map *map)
{
	int     i;
	int     j;
	int     target;

	target = 0;
	i = 0;
	while (map->map_path_check[i])
	{
		j = 0;
		while(map->map_path_check[i][j])
		{
			if (map->map_path_check[i][j] == 'C')
				target++;
                        if (map->map_path_check[i][j] == 'E')
				target++;
			j++;
		}
		i++;
	}
	return(target);
}

void    set_position(t_map *map, int *elem, char c)
{
        int     i;
        int     j;

        i = 0;
        while (map->map_path_check[i])
        {
                j = 0;
                while(map->map_path_check[i][j])
                {
                        if (map->map_path_check[i][j] == c)
                        {
                                elem[0] = i;
                                elem[1] = j;
                        }
                        j++;
                }
                i++;
        }
}

int	move_to_target(t_map *map, int *p, int *t)
{
	if (p[0] > t[0] && map->map_path_check[p[0] - 1][p[1]] != '1')
	{
		map->map_path_check[p[0] - 1][p[1]] = 'P';
		map->map_path_check[p[0]][p[1]] = '0';
		return (1);
	}
	if (p[0] < t[0] && map->map_path_check[p[0] + 1][p[1]] != '1')
	{
		map->map_path_check[p[0] + 1][p[1]] = 'P';
		map->map_path_check[p[0]][p[1]] = '0';
		return (1);
	}
	if (p[1] > t[1] && map->map_path_check[p[0]][p[1] - 1] != '1')
	{
		map->map_path_check[p[0]][p[1] - 1] = 'P';
		map->map_path_check[p[0]][p[1]] = '0';
		return (1);
	}
	if (p[1] < t[1] && map->map_path_check[p[0]][p[1] + 1] != '1')
	{
		map->map_path_check[p[0]][p[1] + 1] = 'P';
		map->map_path_check[p[0]][p[1]] = '0';
		return (1);
	}
	return (0);
}

int     valid_path(t_map *map)
{
        int     p_pos[2];
        int     c_pos[2];
	int     e_pos[2];
	
	set_position(map, e_pos, 'E');
	while (targets_left(map) > 1)
	{
        	set_position(map, p_pos, 'P');
        	set_position(map, c_pos, 'C');
		ft_printf("targets left : %i, player is at %i:%i\n", targets_left(map), p_pos[0], p_pos[1]);
		sleep(1);
		if (!move_to_target(map, p_pos, c_pos))
			return(0);
	}
	while (targets_left(map) != 0)
	{
        	set_position(map, p_pos, 'P');
		ft_printf("targets left : %i, player is at %i:%i\n", targets_left(map), p_pos[0], p_pos[1]);
		sleep(1);
		if (!move_to_target(map, p_pos, e_pos))
			return(0);
	}
	set_position(map, p_pos, 'P');
	ft_printf("targets left : %i, player is at %i:%i\n", targets_left(map), p_pos[0], p_pos[1]);
        return (1);
}
