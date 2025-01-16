CUR_DIR = $(shell pwd)

NAME = push_swap

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/main.c  $(CUR_DIR)/validation_input.c $(CUR_DIR)/push.c \
		$(CUR_DIR)/swap.c $(CUR_DIR)/rotate.c $(CUR_DIR)/rev_rotate.c \
		$(CUR_DIR)/initialisation.c $(CUR_DIR)/sorting.c $(CUR_DIR)/target.c \
		$(CUR_DIR)/move_calculation.c $(CUR_DIR)/move_execution.c $(CUR_DIR)/validation_solution.c

MY_HEADERS = push_swap.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_INCLUDES = $(CUR_DIR)/libft/libft.a

all: $(MY_INCLUDES) $(NAME)

$(MY_INCLUDES):
	$(MAKE) -C $(CUR_DIR)/libft

$(NAME): $(MY_OBJECTS) $(MY_INCLUDES)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(MY_INCLUDES) -o $(NAME)

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(MAKE) -C $(CUR_DIR)/libft clean
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(MAKE) -C $(CUR_DIR)/libft fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
