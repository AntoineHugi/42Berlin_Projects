/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:17 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/10 14:44:19 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_collectibles(char **map_array)
{
	int	i;
	int	j;
	int	collect_count;

	i = 0;
	collect_count = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'C')
				collect_count++;
			j++;
		}
		i++;
	}
	return (collect_count);
}

static void	init_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == 'P')
			{
				map->p_pos[0] = i;
				map->p_pos[1] = j;
			}
			if (map->map_array[i][j] == 'E')
			{
				map->e_pos[0] = i;
				map->e_pos[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	map_init(t_map *map)
{
	int	i;

	map->width = (int)ft_strlen(map->map_array[0]);
	i = 0;
	while (map->map_array[i])
		i++;
	map->height = i;
	map->moves = 0;
	map->old_moves = 0;
	map->old_collect_count = 0;
	init_position(map);
	map->collect_count = count_collectibles(map->map_array);
	map->game_won = 0;
	map->win_clear = 0;
	map->win_x = PIX * map->width + 150;
	map->win_y = PIX * map->height;
}

t_map	*map_creation(char *map_file)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	fd = open(map_file, O_RDONLY);
	if (fd < 2)
	{
		free(map);
		return (NULL);
	}
	map->map_raw = NULL;
	while (1)
	{
		map->line = get_next_line(fd);
		if (!(map->line))
			break ;
		map->map_raw = ft_gnl_strjoin(map->map_raw, map->line);
		free(map->line);
	}
	map->map_array = ft_split(map->map_raw, '\n');
	map->map_path_check = ft_split(map->map_raw, '\n');
	map->map_reset = ft_split(map->map_raw, '\n');
	free(map->map_raw);
	map_init(map);
	return (map);
}
