CUR_DIR = $(shell pwd)

NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

MLX_FLAGS = -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

LIBFT_DIR = $(CUR_DIR)/libft
PRINTF_DIR = $(CUR_DIR)/printf
MLX_DIR = $(CUR_DIR)/mlx_linux

SRCS = $(addprefix $(CUR_DIR)/mandatory/, errors.c free_memory.c initialisation.c key_hook.c main.c \
								map_generation.c map_rendering.c map_valid_path.c map_validation.c \
								moves.c )

SRCS_BONUS = $(addprefix $(CUR_DIR)/bonus/, errors_bonus.c free_memory_bonus.c initialisation_bonus.c key_hook_bonus.c main_bonus.c \
								map_generation_bonus.c map_rendering_bonus.c map_valid_path_bonus.c map_validation_bonus.c \
								moves_bonus.c win_screen_rendering_bonus.c )

MY_HEADERS = mandatory/so_long.h


OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(PRINTF_DIR)

$(MLX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MLX_DIR)
	
%.o: %.c ../$(MY_HEADERS)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 	
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	rm -rf $(MLX_DIR)/build

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:	fclean all

bonus:	$(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -L$(MLX_DIR) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME_BONUS)

.PHONY: all clean fclean re
