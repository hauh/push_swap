/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:15:20 by smorty            #+#    #+#             */
/*   Updated: 2019/06/26 19:12:25 by smorty           ###   ########.fr       */
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

static void	bottom_up(t_stack **a, int **coms)
{
	while ((*a)->left->place < (*a)->right->place)
	{
		reverse(a, coms);
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
	}
}

static void	sort_back(t_stack **a, t_stack **b, int size, int **coms)
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
				push(b, a, coms);
				rotate(a, coms);
			}
			else
				where_to(*b, start) >= 0 ? rotate(b, coms) : reverse(b, coms);
		push(b, a, coms);
		while ((*a)->place == start || (*a)->left->place == start
			|| (*a)->right->place == start)
			--start;
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
	}
}

static int	split(t_stack **a, t_stack **b, int size, int **coms)
{
	int pivot;
	int count;

	pivot = find_lowest(*a, size) + size / 2 + size % 2;
	count = 0;
	while (count * 2 < size + 4)
		if ((*a)->place <= pivot + 1)
		{
			push(a, b, coms);
			++count;
			if ((*b)->place >= pivot)
				rotate(b, coms);
		}
		else
			rotate(a, coms);
	return (count);
}

void		sort_100(t_stack **a, t_stack **b, int size, int **coms)
{
	int count;

	if (size < 4)
		sort_3(a, coms);
	else
	{
		count = split(a, b, size, coms);
		sort_100(a, b, size - count, coms);
		reverse(b, coms);
		reverse(b, coms);
		push(b, a, coms);
		push(b, a, coms);
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
		sort_back(a, b, count - 2, coms);
		bottom_up(a, coms);
	}
}
