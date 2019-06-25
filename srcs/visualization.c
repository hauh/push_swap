/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:30:41 by smorty            #+#    #+#             */
/*   Updated: 2019/06/25 17:51:55 by smorty           ###   ########.fr       */
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

static void	print_graphic(t_stack *a, t_stack *b, int width)
{
	t_stack	*ta;
	t_stack	*tb;
	int		len;

	ta = a;
	tb = b;
	while (ta || tb)
	{
		if (ta)
		{
			ft_printf("| {green}");
			len = 0;
			while (len++ < ta->place)
				ft_printf("■");
			ft_printf("{eoc} %*|", width - ta->place);
			ta = (ta->right == a ? NULL : ta->right);
		}
		else
			ft_printf("|%*|", width + 2);
		if (tb)
		{
			ft_printf("| {yellow}");
			len = 0;
			while (len++ < tb->place)
				ft_printf("■");
			ft_printf("{eoc} %*|\n", width - tb->place);
			tb = (tb->right == b ? NULL : tb->right);
		}
		else
			ft_printf("|%*|\n", width + 2);
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
}

void		print_stacks(t_stack *a, t_stack *b, char *com, int flag)
{
	static int	count = 0;
	static int	width = 0;
	int			s;

	ft_printf("\e[?25l\e[H");
	if (!width)
	{
		ft_printf("\e[J");
		width = (flag / 10 == 1 ? 12 : stack_size(a) + 1);
		if (width < 7)
			width = 7;
	}
	s = width - 5;
	while (s--)
		ft_printf("𝌃");
	ft_printf(" Operation: %3s ", com);
	s = width - 5;
	while (s--)
		ft_printf("𝌃");
	ft_printf("\n");
	flag / 10 == 1 ? print_numbers(a, b) : print_graphic(a, b, width);
	s = width - 4;
	while (s--)
		ft_printf("𝌃");
	ft_printf(" Moves: %5d ", count++);
	s = width - 4;
	while (s--)
		ft_printf("𝌃");
	ft_printf("\n\e[J\e[?25h");
	delay(flag);
}
