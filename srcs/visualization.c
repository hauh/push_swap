/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:30:41 by smorty            #+#    #+#             */
/*   Updated: 2019/06/24 00:02:03 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_numbers(t_stack *a, t_stack *b, char *com)
{
	t_stack *ta;
	t_stack *tb;
	int lines;

	lines = 2;
	ft_printf("𝌃𝌃𝌃𝌃𝌃𝌃𝌃 Operation: %-3s 𝌃𝌃𝌃𝌃𝌃𝌃𝌃\n", com);
	ta = a;
	tb = b;
	while (ta || tb)
	{
		if (ta)
		{
			ft_printf("|%10d   |", ta->n);
			ta = ta->right;
			if (ta == a)
				ta = NULL;
		}
		else
			ft_printf("|             |");
		if (tb)
		{
			ft_printf("|%10d   |\n", tb->n);
			tb = tb->right;
			if (tb == b)
				tb = NULL;
		}
		else
			ft_printf("|             |\n");
		++lines;
	}
	return (lines);
}

static int	print_graphic(t_stack *a, t_stack *b, char *com)
{
	t_stack	*ta;
	t_stack	*tb;
	wchar_t	*line;
	int		size;
	int		lines;

	ft_printf("𝌃𝌃𝌃𝌃𝌃𝌃𝌃 Operation: %-3s 𝌃𝌃𝌃𝌃𝌃𝌃𝌃\n", com);
	ta = a;
	tb = b;
	lines = 2;
	while (ta || tb)
	{
		if (ta)
		{
			size = 0;
			line = (wchar_t *)malloc(sizeof(wchar_t) * (ta->n + 1));
			line[ta->n] = 0;
			while (size < ta->n)
				line[size++] = L'■';
			ft_printf("| {green}%S{eoc} %*|", line, 101 - ta->n);
			ta = ta->right;
			if (ta == a)
				ta = NULL;
			free(line);
		}
		else
			ft_printf("|%*|", 103);
		if (tb)
		{
			size = 0;
			line = (wchar_t *)malloc(sizeof(wchar_t) * (tb->n + 1));
			line[tb->n] = 0;
			while (size < tb->n)
				line[size++] = L'■';
			ft_printf("| {yellow}%S{eoc} %*|\n", line, 101 - tb->n);
			free(line);
			tb = tb->right;
			if (tb == b)
				tb = NULL;
		}
		else
			ft_printf("|%*|\n", 102);
		++lines;
	}
	return (lines);
}

void print_stacks(t_stack *a, t_stack *b, char *com, int flag)
{
	static int	count = 0;
	int			lines;

	lines = 0;
	if (flag == 1)
		lines = print_numbers(a, b, com);
	else if (flag == 2)
		lines = print_graphic(a, b, com);
	usleep(100000);
	ft_printf("𝌃𝌃𝌃𝌃𝌃𝌃𝌃 Moves: %-5d 𝌃𝌃𝌃𝌃𝌃𝌃𝌃\e[J\n\e[s", count);
	count++;
	while (lines--)
		ft_printf("\e[F");
}