/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:48:19 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/04 12:32:43 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	int		color;
}				t_vars;

//add everything else inside map!!
typedef struct s_map {
	char	*map_raw;
	char	*line;
	char	**map_array;
	char	**map_path_check;
	int	height;
	int	width;
}				t_map;


int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

int	input_validation(int argc, char **argv);
int	map_validation(t_map *map);
int     valid_path(t_map *map);
void	error_input(char *str);
void	error_map(char *str, t_map *map);
t_map	*map_creation(char *map_file);

#endif
