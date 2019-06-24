/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:30:41 by smorty            #+#    #+#             */
/*   Updated: 2019/06/24 23:27:14 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_numbers(t_stack *a, t_stack *b)
{
	t_stack *ta;
	t_stack *tb;

	ta = a;
	tb = b;
	while (ta || tb)
	{
		if (ta)
		{
			ft_printf("|%10d   |", ta->n);
			ta = (ta->right == a ? NULL : ta->right);
		}
		else
			ft_printf("|             |");
		if (tb)
		{
			ft_printf("|%10d   |\n", tb->n);
			tb = (tb->right == b ? NULL : tb->right);
		}
		else
			ft_printf("|             |\n");
	}
}

static void	print_graphic(t_stack *a, t_stack *b, int size)
{
	t_stack	*ta;
	t_stack	*tb;
	int		width;

	ta = a;
	tb = b;
	while (ta || tb)
	{
		if (ta)
		{
			ft_printf("| {green}");
			width = 0;
			while (width++ < ta->place)
				ft_printf("■");
			ft_printf("{eoc} %*|", size - ta->place);
			ta = (ta->right == a ? NULL : ta->right);
		}
		else
			ft_printf("|%*|", size + 2);
		if (tb)
		{
			ft_printf("| {yellow}");
			width = 0;
			while (width++ < tb->place)
				ft_printf("■");
			ft_printf("{eoc} %*|\n", size - tb->place);
			tb = (tb->right == b ? NULL : tb->right);
		}
		else
			ft_printf("|%*|\n", size + 2);
	}
}

static void	delay(int flag)
{
	char input;

	if (flag % 10)
		usleep(flag % 10 * 100000);
	else
	{
		input = 0;
		while (input != '\n')
		{
			ft_printf("\e[JPress enter to continue");
			read(1, &input, 1);
		}
		ft_printf("\e[F\e[J");
	}
	ft_printf("\e[s\e[H");
}

void		print_stacks(t_stack *a, t_stack *b, char *com, int flag)
{
	static int	count = 0;
	static int	size = 0;
	int			s;

	if (!size)
	{
		ft_printf("\e[?25l\e[H\e[J");
		size = (flag / 10 == 1 ? 12 : stack_size(a) + 1);
		if (size < 7)
			size = 7;
	}
	s = size - 5;
	while (s--)
		ft_printf("𝌃");
	ft_printf(" Operation: %3s ", com);
	s = size - 5;
	while (s--)
		ft_printf("𝌃");
	ft_printf("\n");
	flag / 10 == 1 ? print_numbers(a, b) : print_graphic(a, b, size);
	s = size - 4;
	while (s--)
		ft_printf("𝌃");
	ft_printf(" Moves: %5d ", count++);
	s = size - 4;
	while (s--)
		ft_printf("𝌃");
	ft_printf("\n\e[J");
	delay(flag);
}
