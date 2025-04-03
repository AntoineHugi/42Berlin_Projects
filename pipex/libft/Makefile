CUR_DIR = $(shell pwd)

NAME = libft.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(addprefix $(CUR_DIR)/,	ft_bzero.c ft_calloc.c ft_memcpy.c ft_split.c \
					ft_strjoin.c ft_strlen.c ft_strncmp.c \
					get_next_line.c get_next_line_utils.c)

MY_HEADERS = libft.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all:	$(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS) 

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(RM) $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
