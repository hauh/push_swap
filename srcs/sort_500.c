/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:37:39 by smorty            #+#    #+#             */
/*   Updated: 2019/06/28 22:42:11 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_ascending(t_stack **a, int **ops)
{
	int one;
	int two;
	int three;

	one = (*a)->place;
	two = (*a)->right->place;
	three = (*a)->right->right->place;
	if (one > two && one > three && two < three)
		if (stack_size(*a) == 3)
			swap(a, ops);
		else
		{
			swap(a, ops);
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
		}
	else if (one > two && one > three && two > three)
		if (stack_size(*a) == 3)
		{
			rotate(a, ops);
			swap(a, ops);
		}
		else
		{
			swap(a, ops);
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
			swap(a, ops);
		}
	else if (two > one && two > three && one < three)
		if (stack_size(*a) == 3)
		{
			reverse(a, ops);
			swap(a, ops);
		}
		else
		{
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
		}
	else if (two > one && two > three && one > three)
		if (stack_size(*a) == 3)
			reverse(a, ops);
		else
		{
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
			swap(a, ops);
		}
	else if (three > one && three > two && one > two)
		swap(a, ops);
}

static void	sort_3_descending(t_stack **a, int **ops)
{
	int one;
	int two;
	int three;

	one = (*a)->place;
	two = (*a)->right->place;
	three = (*a)->right->right->place;
	if (one > two && one > three && two < three)
		if (stack_size(*a) == 3)
		{
			reverse(a, ops);
			swap(a, ops);
		}
		else
		{
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
		}
	else if (two > one && two > three && one < three)
		if (stack_size(*a) == 3)
			rotate(a, ops);
		else
		{
			swap(a, ops);
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
		}
	else if (two > one && two > three && one > three)
		swap(a, ops);
	else if (three > one && three > two && one > two)
		if (stack_size(*a) == 3)
			reverse(a, ops);
		else
		{
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
			swap(a, ops);
		}
	else if (three > one && three > two && one < two)
	{
		if (stack_size(*a) == 3)
		{
			swap(a, ops);
			reverse(a, ops);
		}
		else
		{
			swap(a, ops);
			rotate(a, ops);
			swap(a, ops);
			reverse(a, ops);
			swap(a, ops);
		}
	}
}

static int	split(t_stack **a, t_stack **b, int size, int **ops)
{
	int pivot;
	int pushed;
	int rotated;

	pivot = (*a)->ab == 'a' ? find_lowest(*a, size) : find_highest(*a, size);
	pivot += (*a)->ab == 'a' ? size / 2 : -(size / 2);
	pushed = 0;
	rotated = 0;
	while (size--)
		if (((*a)->ab == 'a' && (*a)->place <= pivot) ||
			((*a)->ab == 'b' && (*a)->place >= pivot))
		{
			push(a, b, ops);
			(*b)->place == pivot ? rotate(b, ops) : ++pushed;
		}
		else
		{
			rotate(a, ops);
			++rotated;
		}
	if (stack_size(*a) > rotated)
		while (rotated--)
			reverse(a, ops);
	return (pushed);
}

void		sort_500(t_stack **a, t_stack **b, int size, int **ops)
{
	int pushed;

	if (size == 2 && (((*a)->ab == 'a' && (*a)->place > (*a)->right->place)
		|| ((*a)->ab == 'b' && (*a)->place < (*a)->right->place)))
		swap(a, ops);
	else if (size == 3 && (*a)->ab == 'a')
		sort_3_ascending(a, ops);
	else if (size == 3 && (*a)->ab == 'b')
		sort_3_descending(a, ops);
	else if (size > 3)
	{
		pushed = split(a, b, size, ops);
		sort_500(a, b, size - pushed - 1, ops);
		reverse(b, ops);
		push(b, a, ops);
		sort_500(b, a, pushed, ops);
		while (pushed--)
			push(b, a, ops);
	}
}
