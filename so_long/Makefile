CUR_DIR = $(shell pwd)

NAME = so_long.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

LIBFT_DIR = $(CUR_DIR)/libft
MLX_DIR = $(CUR_DIR)/mlx_linux

SRCS = $(addprefix $(CUR_DIR)/, main.c  validation_input.c push.c \
		swap.c rotate.c rev_rotate.c \
		initialisation.c sorting.c target.c \
		move_calculation.c move_execution.c validation_solution.c)

MY_HEADERS = so_long.h

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

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
