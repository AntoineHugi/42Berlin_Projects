CUR_DIR = $(shell pwd)

NAME = pipex

NAME_BONUS = pipex_bonus

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

LIBFT_DIR = $(CUR_DIR)/libft

SRCS = $(addprefix $(CUR_DIR)/mandatory/, helper_functions.c pipex.c run_cmd.c )

SRCS_BONUS = $(addprefix $(CUR_DIR)/bonus/, helper_functions_bonus.c parent_child_process.c pipex_bonus.c run_cmd_bonus.c )

MY_HEADERS = $(CUR_DIR)/includes/pipex.h

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)
	
%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:	fclean all

bonus: $(LIBFT_DIR)/libft.a $(OBJS_BONUS) 
	$(CC) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

.PHONY: all clean fclean re
