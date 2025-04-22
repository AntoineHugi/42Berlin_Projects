CUR_DIR = $(shell pwd)

NAME = philo

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --trace-children=yes

SRCS = $(addprefix $(CUR_DIR)/src/, errors.c freeing.c initialisation.c main.c printing.c routines.c start_meal.c utils.c)

MY_HEADERS = $(CUR_DIR)/includes/so_long.h

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
%.o: %.c ../$(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

valgrind: $(LIBFT_DIR)/libft.a $(NAME)
	valgrind $(VALGRIND_FLAGS) ./$(NAME)

.PHONY: all clean fclean re
