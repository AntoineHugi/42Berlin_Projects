CUR_DIR = $(shell pwd)

NAME = libft.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/ft_atoi.c $(CUR_DIR)/ft_atoll.c $(CUR_DIR)/ft_isdigit.c \
	    $(CUR_DIR)/ft_split.c $(CUR_DIR)/ft_strlen.c $(CUR_DIR)/ft_strncmp.c \
		$(CUR_DIR)/ft_lstadd_back.c $(CUR_DIR)/ft_lstadd_front.c $(CUR_DIR)/ft_lstlast.c \
		$(CUR_DIR)/ft_lstnew.c $(CUR_DIR)/ft_lstsize.c

MY_HEADERS = libft.h

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
