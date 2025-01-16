CUR_DIR = $(shell pwd)

NAME = so_long

CC = cc

MLX_FLAGS = -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

LIBFT_DIR = $(CUR_DIR)/libft
MLX_DIR = $(CUR_DIR)/mlx_linux

SRCS = $(addprefix $(CUR_DIR)/, test.c)

MY_HEADERS = so_long.h

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MLX_DIR)
	

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 	
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	rm -rf $(MLX_DIR)/build

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
