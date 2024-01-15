NAME = fractol

CC = gcc

SRCS = main.c color.c hooks.c loops.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
LIBMLX = libmlx/libmlx.a

CFLAGS = -Wall -Werror -Wextra -MMD -I libft -I printf -I libmlx

LDFLAGS = -L libft -L printf -l ft -l ftprintf -L libmlx -l mlx -framework OpenGL -framework AppKit

all: 
	@$(MAKE) $(NAME) 

$(NAME): $(LIBFT) $(PRINTF) $(LIBMLX) $(OBJS)
	@echo "Fractol compiled!"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C printf

$(LIBMLX):
	@make -C libmlx

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean
	$(MAKE) -C libmlx clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
