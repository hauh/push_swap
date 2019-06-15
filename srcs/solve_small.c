/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:20:39 by smorty            #+#    #+#             */
/*   Updated: 2019/06/15 20:29:00 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_3(t_stack **s, int **coms)
{
	if ((*s)->ab == 'a')
		while ((*s)->place > (*s)->right->place ||
			(*s)->right->place > (*s)->left->place)
		{
			if ((*s)->place > (*s)->left->place)
				rotate(s, coms);
			else if ((*s)->place > (*s)->right->place)
				swap(s, coms);
			else if ((*s)->right->place > (*s)->left->place)
				reverse(s, coms);
		}
	else
		while ((*s)->place < (*s)->right->place ||
			(*s)->right->place < (*s)->left->place)
		{
			if ((*s)->place < (*s)->left->place)
				rotate(s, coms);
			else if ((*s)->place < (*s)->right->place)
				swap(s, coms);
			else if ((*s)->right->place < (*s)->left->place)
				reverse(s, coms);
		}
}

int		is_sorted_back(t_stack *s, int size)
{
	t_stack *r;

	r = s;
	r = r->right;
	--size;
	while (r != s && r->place < r->left->place)
	{
		r = r->right;
		--size;
	}
	if (size != 0)
		return (0);
	return (1);
}

void	solve_5_b(t_stack **a, t_stack **b, int size, int **coms)
{
	int i;

	if (!is_sorted_back(*a, size))
	{
		i = (size == 5 ? 2 : 1);
		while (i)
		{
			if ((*a)->place > 3)
			{
				push(a, b, coms);
				--i;
			}
			else if	((*a)->left->place > 3)
				reverse(a, coms);
			else
				rotate(a, coms);
		}
		solve_3(a, coms);
		if (size == 5)
		{
			if ((*b)->place > (*b)->right->place)
				swap(b, coms);
			push(b, a, coms);
		}
		push(b, a, coms);
	}
}

void	solve_5_a(t_stack **a, t_stack **b, int size, int **coms)
{
	int i;
	int t;

	if (!is_sorted(*a, size))
	{
		i = (size == 5 ? 2 : 1);
		t = find_lowest(*a) + i - 1;
		while (i)
		{
			if ((*a)->place <= t)
			{
				push(a, b, coms);
				--i;
			}
			else if	((*a)->left->place <= t)
				reverse(a, coms);
			else
				rotate(a, coms);
		}
		solve_3(a, coms);
		if (size == 5)
		{
			if ((*b)->place < (*b)->right->place)
				swap(b, coms);
			push(b, a, coms);
		}
		push(b, a, coms);
	}
}
