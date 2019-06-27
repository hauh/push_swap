/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:20:39 by smorty            #+#    #+#             */
/*   Updated: 2019/06/28 00:08:14 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **s, int **ops)
{
	while ((*s)->place > (*s)->right->place ||
		(*s)->right->place > (*s)->left->place)
	{
		if ((*s)->place > (*s)->left->place)
			rotate(s, ops);
		else if ((*s)->place > (*s)->right->place)
			swap(s, ops);
		else if ((*s)->right->place > (*s)->left->place)
			reverse(s, ops);
	}
}

void	sort_5(t_stack **a, t_stack **b, int size, int **ops)
{
	int i;
	int top;

	if (!is_sorted(*a, size))
	{
		i = (size == 5 ? 2 : 1);
		top = find_lowest(*a, size) + i - 1;
		while (i)
		{
			if ((*a)->place <= top)
			{
				push(a, b, ops);
				--i;
			}
			else if	((*a)->left->place <= top)
				reverse(a, ops);
			else
				rotate(a, ops);
		}
		sort_3(a, ops);
		if (size == 5)
		{
			if ((*b)->place < (*b)->right->place)
				swap(b, ops);
			push(b, a, ops);
		}
		push(b, a, ops);
	}
}
