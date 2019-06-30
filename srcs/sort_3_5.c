/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:20:39 by smorty            #+#    #+#             */
/*   Updated: 2019/07/01 00:26:41 by smorty           ###   ########.fr       */
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
