NAME = fractol

CC = gcc

SRCS = main.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra -MMD -I libft -I printf

LDFLAGS = -L libft -L printf -l ft -l ftprintf

all: 
	$(MAKE) $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf


clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
