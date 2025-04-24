CUR_DIR = $(shell pwd)

NAME = philo

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

SRCS = $(addprefix $(CUR_DIR)/src/, errors.c freeing.c initialisation.c main.c obs_routine.c philo_routines.c printing.c start_meal.c utils.c)

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

.PHONY: all clean fclean re
