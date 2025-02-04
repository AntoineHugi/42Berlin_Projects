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

t_map	*map_creation(char *map_file)
{
	t_map	*map;
	int	fd;
	int	i;

	map = (t_map *)malloc(sizeof(t_map));
	fd = open(map_file, O_RDONLY);
	if (fd < 2)
		return (NULL);
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
	map->height = i;
	map->map_array = ft_split(map->map_raw, '\n');
	map->map_path_check = ft_split(map->map_raw, '\n');
	free(map->map_raw);
	map->width = (int)ft_strlen(map->map_array[0]);
	return (map);
}
