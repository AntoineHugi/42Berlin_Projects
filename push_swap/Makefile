CUR_DIR = $(shell pwd)

NAME = push_swap.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/push_swap.c $(CUR_DIR)/.c $(CUR_DIR)/.c \
	    $(CUR_DIR)/.c $(CUR_DIR)/.c $(CUR_DIR)/.c \
	    $(CUR_DIR)/.c $(CUR_DIR)/.c $(CUR_DIR)/.c

MY_HEADERS = push_swap.h

MY_INCLUDES = $(CUR_DIR)/libft/libft.a \
		$(CUR_DIR)/ft_printf/libftprintf.a

LIBFT_MAKEFILE = $(CUR_DIR)/libft/Makefile
FT_PRINTF_MAKEFILE = $(CUR_DIR)/ft_printf/Makefile

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(MY_INCLUDES) $(NAME)

$(MY_INCLUDES):
	$(MAKE) -C $(CUR_DIR)/libft
	$(MAKE) -C $(CUR_DIR)/ft_printf

$(NAME): $(MY_OBJECTS) 
	ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(MAKE) -C $(CUR_DIR)/libft clean
	$(MAKE) -C $(CUR_DIR)/ft_printf clean
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(MAKE) -C $(CUR_DIR)/libft fclean
	$(MAKE) -C $(CUR_DIR)/ft_printf fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
