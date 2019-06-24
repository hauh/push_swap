# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorty <smorty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 23:29:04 by smorty            #+#    #+#              #
#    Updated: 2019/06/24 19:03:43 by smorty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRCDIR = srcs/

LIB = $(SRCDIR)libft/

LIBPRINTF = $(SRCDIR)ft_printf/

SRCS1 = $(addprefix $(SRCDIR),push_swap.c utility.c array.c operators.c stacks.c solve_small.c sort_100.c sort_500.c optimization.c visualization.c)

SRCS2 = $(addprefix $(SRCDIR),checker.c utility.c array.c operators.c stacks.c visualization.c get_next_line/get_next_line.c)

CC = gcc -Wall -Werror -Wextra -g

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCS1)
	$(CC) $^ -L$(LIB) -lft -L$(LIBPRINTF) -lftprintf -o $@

$(NAME2): $(SRCS2)
	$(CC) $^ -L$(LIB) -lft -L$(LIBPRINTF) -lftprintf -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME1) $(NAME2)

re: fclean all
