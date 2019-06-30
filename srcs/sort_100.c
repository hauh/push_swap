/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:15:20 by smorty            #+#    #+#             */
/*   Updated: 2019/06/30 19:16:48 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	where_to(t_stack *s, int place)
{
	t_stack	*r;
	int		direction;

	direction = 0;
	r = s;
	while (r->place != place)
	{
		r = r->right;
		--direction;
	}
	r = s;
	while (r->place != place)
	{
		r = r->left;
		++direction;
	}
	return (direction);
}

static void	bottom_up(t_stack **a, int **ops)
{
	while ((*a)->left->place < (*a)->right->place)
	{
		reverse(a, ops);
		if ((*a)->place > (*a)->right->place)
			swap(a, ops);
	}
}

static void	sort_back(t_stack **a, t_stack **b, int size, int **ops)
{
	int start;
	int end;

	start = find_highest(*b, size);
	end = find_lowest(*b, size);
	while (end <= start)
	{
		while ((*b)->place != start && (*b)->place != start - 1)
			if ((*b)->place == end || (*b)->place == end + 1)
			{
				if ((*b)->place == end)
					end += 1 + ((*a)->left->place == end + 1);
				push(b, a, ops);
				rotate(a, ops);
			}
			else
				where_to(*b, start) >= 0 ? rotate(b, ops) : reverse(b, ops);
		push(b, a, ops);
		while ((*a)->place == start || (*a)->left->place == start
			|| (*a)->right->place == start)
			--start;
		if ((*a)->place > (*a)->right->place)
			swap(a, ops);
	}
}

static int	split(t_stack **a, t_stack **b, int size, int **ops)
{
	int pivot;
	int count;

	pivot = find_lowest(*a, size) + size / 2 + size % 2;
	count = 0;
	while (count * 2 < size + 4)
		if ((*a)->place <= pivot + 1)
		{
			push(a, b, ops);
			++count;
			if ((*b)->place >= pivot)
				rotate(b, ops);
		}
		else
			rotate(a, ops);
	return (count);
}

void		sort_100(t_stack **a, t_stack **b, int size, int **ops)
{
	int count;

	if (size <= 3)
		sort_3(a, ops);
	else if (size <= 5)
		sort_5(a, b, size, ops);
	else
	{
		count = split(a, b, size, ops);
		sort_100(a, b, size - count, ops);
		reverse(b, ops);
		reverse(b, ops);
		push(b, a, ops);
		push(b, a, ops);
		if ((*a)->place > (*a)->right->place)
			swap(a, ops);
		sort_back(a, b, count - 2, ops);
		bottom_up(a, ops);
	}
}
