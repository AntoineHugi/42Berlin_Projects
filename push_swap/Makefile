CUR_DIR = $(shell pwd)

NAME = push_swap.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/push_swap.c $(CUR_DIR)/push.c $(CUR_DIR)/swap.c \
	    $(CUR_DIR)/rotate.c $(CUR_DIR)/rev_rotate.c $(CUR_DIR)/input_validation.c \
	    $(CUR_DIR)/sorting.c $(CUR_DIR)/initialisation.c $(CUR_DIR)/position.c \
		$(CUR_DIR)/move_calculation.c

MY_HEADERS = push_swap.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_INCLUDES = $(CUR_DIR)/libft/libft.a $(CUR_DIR)/ft_printf/libftprintf.a

LIBFT_MAKEFILE = $(CUR_DIR)/libft/Makefile
FT_PRINTF_MAKEFILE = $(CUR_DIR)/ft_printf/Makefile

LIBFT = $(CUR_DIR)/libft/libft.a
FT_PRINTF = $(CUR_DIR)/ft_printf/libftprintf.a

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(MY_INCLUDES):
	$(MAKE) -C $(CUR_DIR)/libft
	$(MAKE) -C $(CUR_DIR)/ft_printf

$(LIBFT):
	$(MAKE) -C $(CUR_DIR)/libft

$(FT_PRINTF):
	$(MAKE) -C $(CUR_DIR)/ft_printf

$(NAME): $(MY_OBJECTS) $(LIBFT) $(FT_PRINTF)
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
