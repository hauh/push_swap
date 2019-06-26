# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorty <smorty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 23:29:04 by smorty            #+#    #+#              #
#    Updated: 2019/06/26 23:15:37 by smorty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRCDIR = srcs/

OBJDIR = $(SRCDIR)obj/

LFTDIR = $(SRCDIR)libft/

LFT = $(LFTDIR)libft.a

LFTPRINTFDIR = $(SRCDIR)ft_printf/

LFTPRINTF = $(LFTPRINTFDIR)libftprintf.a

SRCS1 = $(addprefix $(SRCDIR),push_swap.c utility.c array.c operators.c stacks.c solve_small.c sort_100.c sort_500.c optimization.c visualization.c)

SRCS2 = $(addprefix $(SRCDIR),checker.c utility.c array.c operators.c stacks.c visualization.c get_next_line/get_next_line.c)

OBJ1 = $(SRCS1:%.c=$(OBJDIR)%.o)

OBJ2 = $(SRCS2:%.c=$(OBJDIR)%.o)

CC = gcc -Wall -Werror -Wextra -g

all: $(NAME1) $(NAME2)

$(LFT):
	@$(MAKE) -C $(LFTDIR)
	@$(MAKE) -C $(LFTDIR) clean

$(LFTPRINTF):
	@$(MAKE) -C $(LFTPRINTFDIR)
	@$(MAKE) -C $(LFTPRINTFDIR) clean

$(NAME1): $(OBJ1) $(LFT) $(LFTPRINTF)
	@$(CC) -L$(LFTDIR) -lft -L$(LFTPRINTFDIR) -lftprintf $^ -o $@
	@echo "$(NAME1) done!"

$(NAME2): $(OBJ2) $(LFT) $(LFTPRINTF)
	@$(CC) -L$(LFTDIR) -lft -L$(LFTPRINTFDIR) -lftprintf $^ -o $@
	@echo "$(NAME2) done!"

$(OBJDIR)%.o: %.c
	@mkdir -p '$(@D)'
	@$(CC) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LFTDIR) fclean
	@$(MAKE) -C $(LFTPRINTFDIR) fclean

fclean: clean
	@rm -f $(NAME1) $(NAME2)

re: fclean all
