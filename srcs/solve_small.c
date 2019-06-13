/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:20:39 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 23:03:55 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_3(t_stack **s)
{
	if ((*s)->ab == 'a')
		while ((*s)->place > (*s)->right->place ||
			(*s)->right->place > (*s)->left->place)
		{
			if ((*s)->place > (*s)->left->place)
				rotate(s);
			else if ((*s)->place > (*s)->right->place)
				swap(s);
			else if ((*s)->right->place > (*s)->left->place)
				reverse(s);
		}
	else
		while ((*s)->place < (*s)->right->place ||
			(*s)->right->place < (*s)->left->place)
		{
			if ((*s)->place < (*s)->left->place)
				rotate(s);
			else if ((*s)->place < (*s)->right->place)
				swap(s);
			else if ((*s)->right->place < (*s)->left->place)
				reverse(s);
		}
}

void	solve_5(t_stack **a, t_stack **b, int size)
{
	int count;

	if (!is_sorted(*a, size))
	{
		count = 2;
		while (count)
		{
			if ((*a)->place < 3)
			{
				push(a, b);
				--count;
			}
			else if	((*a)->left->place < 3 || (*a)->left->left->place < 3)
				reverse(a);
			else
				rotate(a);
		}
		solve_3(a);
		if ((*b)->place < (*b)->right->place)
			swap(b);
		push(b, a);
		push(b, a);
	}
}
