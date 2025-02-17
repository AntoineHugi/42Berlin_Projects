CUR_DIR = $(shell pwd)

NAME = pipex

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

LIBFT_DIR = $(CUR_DIR)/libft
PRINTF_DIR = $(CUR_DIR)/printf

SRCS = $(addprefix $(CUR_DIR)/mandatory/, helper_functions.c pipex.c run_cmd.c )

SRCS_BONUS = $(addprefix $(CUR_DIR)/bonus/, helper_functions_bonus.c pipex_bonus.c run_cmd_bonus.c  )

MY_HEADERS = $(CUR_DIR)/includes/pipex.h

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(PRINTF_DIR)
	
%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re:	fclean all

bonus: $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

.PHONY: all clean fclean re
