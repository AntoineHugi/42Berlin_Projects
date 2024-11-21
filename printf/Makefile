CUR_DIR = $(shell pwd)

NAME = libftprintf.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/ft_printf.c \
	     $(CUR_DIR)/ft_itoa_base.c \
	     $(CUR_DIR)/ft_toupper_str.c

MY_LIBRARY = $(CUR_DIR)/libft/libft.a

MY_HEADERS = libftprintf.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all:	$(NAME) 

$(NAME): $(MY_OBJECTS) $(MY_LIBRARY)
	ar rcs $(NAME) $(MY_OBJECTS)  $(MY_LIBRARY)

$(MY_LIBRARY):
	$(MAKE) -C $(CUR_DIR)/libft all

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(RM) $(MY_OBJECTS)
	$(MAKE) -C $(CUR_DIR)/libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(CUR_DIR)/libft fclean

re:	fclean all

.PHONY: all clean fclean re $(MY_LIBRARY)
