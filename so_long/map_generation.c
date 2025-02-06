/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:17 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/04 12:31:19 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void count_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collect_count = 0;
	while (map->map_array[i])
	{
		j = 0;
		while(map->map_array[i][j])
		{
			if (map->map_array[i][j] == 'C')
				map->collect_count++;
			j++;
		}
		i++;
	}
}

static void	init_position(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while(map->map_array[i][j])
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

void	map_init(t_map *map, int i)
{
	map->width = (int)ft_strlen(map->map_array[0]);
	map->height = i;
	map->moves = 0;
	init_position(map);
	count_collectibles(map);
}

t_map	*map_creation(char *map_file)
{
	t_map	*map;
	int	fd;
	int	i;

	map = (t_map *)malloc(sizeof(t_map));
	fd = open(map_file, O_RDONLY);
	if (fd < 2)
	{
		free(map);
		return (NULL);
	}
	map->map_raw = NULL;
	i = 0;
	while (1)
	{
		map->line = get_next_line(fd);
		if (!(map->line))
			break;
		map->map_raw = ft_gnl_strjoin(map->map_raw, map->line);
		free(map->line);
		i++;
	}
	map->map_array = ft_split(map->map_raw, '\n');
	//instead of creating a new map for check, could create a copy in the checker.
	//create a copy of map for restart function
	map->map_path_check = ft_split(map->map_raw, '\n');
	free(map->map_raw);
	map_init(map, i);
	return (map);
}
