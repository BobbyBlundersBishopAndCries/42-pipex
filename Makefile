
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = biba_utils.c pipex.c
BONUS = 
OBJS = $(SRCS:.c=.o)
B_OBJS = $(BONUS:.c=.o)
NAME = pipex
BONUS_NAME = pipex_bonus

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
bonus: $(BONUS)

$(BONUS_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(B_OBJS) $(LIBFT)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
