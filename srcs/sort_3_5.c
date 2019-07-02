/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:20:39 by smorty            #+#    #+#             */
/*   Updated: 2019/07/02 17:24:46 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** var 1 = 312, var 2 = 132, var 3 = 213, var 4 = 231, var 5 = 123, var 6 = 321
*/

static void	sort_3_v0(t_stack **s, int **ops, int var)
{
	if ((var == 1 && (*s)->ab == 'a') || (var == 2 && (*s)->ab == 'b'))
		rotate(s, ops);
	else if ((var == 2 && (*s)->ab == 'a') || (var == 1 && (*s)->ab == 'b'))
	{
		swap(s, ops);
		rotate(s, ops);
	}
	else if ((var == 3 && (*s)->ab == 'a') || (var == 4 && (*s)->ab == 'b'))
		swap(s, ops);
	else if ((var == 4 && (*s)->ab == 'a') || (var == 3 && (*s)->ab == 'b'))
		reverse(s, ops);
	if ((var == 6 && (*s)->ab == 'a') || (var == 5 && (*s)->ab == 'b'))
	{
		rotate(s, ops);
		swap(s, ops);
	}
}

static void	sort_3_v1(t_stack **s, int **ops, int var)
{
	if ((var == 1 && (*s)->ab == 'a') || (var == 2 && (*s)->ab == 'b'))
	{
		swap(s, ops);
		rotate(s, ops);
		swap(s, ops);
		reverse(s, ops);
	}
	else if ((var == 2 && (*s)->ab == 'a') || (var == 1 && (*s)->ab == 'b'))
	{
		rotate(s, ops);
		swap(s, ops);
		reverse(s, ops);
	}
}

static void	sort_3_v2(t_stack **s, int **ops, int var)
{
	if ((var == 6 && (*s)->ab == 'a') || (var == 5 && (*s)->ab == 'b'))
	{
		swap(s, ops);
		rotate(s, ops);
		swap(s, ops);
		reverse(s, ops);
		swap(s, ops);
	}
	else if ((var == 4 && (*s)->ab == 'a') || (var == 3 && (*s)->ab == 'b'))
	{
		rotate(s, ops);
		swap(s, ops);
		reverse(s, ops);
		swap(s, ops);
	}
	else if ((var == 3 && (*s)->ab == 'a') || (var == 4 && (*s)->ab == 'b'))
		swap(s, ops);
}

void		sort_3(t_stack **s, int **ops)
{
	int var;
	int top;
	int middle;
	int bottom;

	var = 0;
	top = (*s)->place;
	middle = (*s)->right->place;
	bottom = (*s)->right->right->place;
	if (top > bottom && bottom > middle)
		var = 1;
	else if (top < bottom && bottom < middle)
		var = 2;
	else if (top > middle && bottom > top)
		var = 3;
	else if (top > bottom && middle > top)
		var = 4;
	else if (top < middle && middle < bottom)
		var = 5;
	else if (top > middle && middle > bottom)
		var = 6;
	if (stack_size(*s) == 3)
		sort_3_v0(s, ops, var);
	else
		var <= 2 ? sort_3_v1(s, ops, var) : sort_3_v2(s, ops, var);
}

void		sort_5(t_stack **a, t_stack **b, int size, int **ops)
{
	while (stack_size(*a) > 3)
	{
		if (is_sorted(*a, size))
			return ;
		else if ((*a)->place < size - 2)
			push(a, b, ops);
		else if ((*a)->left->place < size - 2)
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
