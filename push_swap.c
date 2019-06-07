/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:40:49 by smorty            #+#    #+#             */
/*   Updated: 2019/06/07 22:13:29 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	print_stack(t_stack *st)
{
	static int count = 1;

	printf("\n-----------%d-----------\n", count++);
	while (st)
	{
		printf("%d ", st->n);
		st = st->next;
	}
}

void	solve(t_stack **a, t_stack **b)
{
	int check;
	static int count = 0;

	print_stack(*a);
	while (*a)
	{
		check = (*a)->n;
		rotate(a);
		++count;
		while ((*a)->n != check)
		{
			if ((*a)->n < check)
				check = (*a)->n;
			rotate(a);
			++count;
		}
		push(a, b);
		++count;
		++count;
	}
	push(a, b);
	print_stack(*b);
	while (*b)
	{
		push(b, a);
		++count;
	}
	print_stack(*a);
	printf("\noperations: %d", count);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (-1);
	a = store_stack(argc - 1, argv + 1);
	b = NULL;
	solve(&a, &b);
	return (0);
}