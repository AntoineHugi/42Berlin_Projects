CUR_DIR = $(shell pwd)

NAME = push_swap.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/.c $(CUR_DIR)/.c $(CUR_DIR)/.c \
	    $(CUR_DIR)/.c $(CUR_DIR)/.c $(CUR_DIR)/.c \
	    $(CUR_DIR)/.c $(CUR_DIR)/.c $(CUR_DIR)/.c

MY_HEADERS = .h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all:	$(NAME) 

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
