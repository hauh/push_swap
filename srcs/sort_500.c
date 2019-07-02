/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:37:39 by smorty            #+#    #+#             */
/*   Updated: 2019/07/02 15:32:36 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (size == 3)
		sort_3(a, ops);
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
