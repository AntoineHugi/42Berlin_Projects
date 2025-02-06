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

# define WIN_W 1000
# define WIN_H 600
# define UP	1
# define DOWN	2
# define RIGHT	3
# define LEFT	4

# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define CHICKEN_XPM			"assets/sprites/chicken.xpm"
# define PLAYER_XPM			"assets/sprites/player.xpm"
# define EXIT_XPM			"assets/sprites/exit.xpm"

# include <mlx.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_map {
	char	*map_raw;
	char	*line;
	char	**map_array;
	char	**map_path_check;
	int		height;
	int		width;
	int		tile_h;
	int		tile_w;
	int		p_pos[2];
	int		e_pos[2];
	int		moves;
	int		collect_count;
}				t_map;

typedef struct s_sprite {
	void	*xpm_ptr;
	int		x;
	int		y;
}				t_sprite;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	t_img	*img;
	t_map	*map;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	player;
	t_sprite	chicken;
	t_sprite	exit;
	int		color;
}				t_game;



int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

int		input_validation(int argc, char **argv);
int		map_validation(t_map *map);
int		key_hook(int keycode, t_game *game);
int		valid_path(t_map *map);
int		exit_app(t_game *game);
void	error_input(char *str);
void	error_map(char *str, t_map *map);
void	init_game(t_game *game);
t_map	*map_creation(char *map_file);

#endif
