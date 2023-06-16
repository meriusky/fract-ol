# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 18:28:12 by mehernan          #+#    #+#              #
#    Updated: 2022/12/26 19:06:49 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

SRCS = ft_printf.c ft_character.c filter.c ft_string.c ft_pointer.c ft_decimal.c \
		ft_hexadecimal_cap.c ft_hexadecimal_min.c ft_num_no_sign.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -MMD -MP

DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
