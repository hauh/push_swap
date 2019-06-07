# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorty <smorty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 23:29:04 by smorty            #+#    #+#              #
#    Updated: 2019/06/07 23:45:03 by smorty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

SRCDIR = srcs/

LIB = $(SRCDIR)libft/

SRCS1 = $(addprefix $(SRCDIR),push_swap.c operators.c stacks.c)

CC = gcc -Wall -Werror -Wextra

all: $(NAME1)

$(NAME1): $(SRCS1)
	$(CC) $^ -L$(LIB) -lft -o $(NAME1)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME1)

re: fclean all
