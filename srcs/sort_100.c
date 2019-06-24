/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:15:20 by smorty            #+#    #+#             */
/*   Updated: 2019/06/24 20:10:42 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	where_to(t_stack *s, int place)
{
	t_stack	*rotate;
	int		direction;

	direction = 0;
	rotate = s;
	while (rotate->place != place)
	{
		rotate = rotate->right;
		++direction;
	}
	rotate = s;
	while (rotate->place != place)
	{
		rotate = rotate->left;
		--direction;
	}
	return (direction);
}

static void	sort_back(t_stack **a, t_stack **b, int size, int **coms)
{
	int start;
	int end;

	start = find_highest(*b, size);
	end = find_lowest(*b, size);
	while (end <= start)
	{
		if (where_to(*b, start) < 0)
			while ((*b)->place != start)
			{
				if ((*b)->place == start - 1)
					push(b, a, coms);
				else if ((*b)->place == end || (*b)->place == end + 1)
				{
					push(b, a, coms);
					rotate(a, coms);
				}
				else
					rotate(b, coms);
			}
		else
			while ((*b)->place != start)
			{
				if ((*b)->place == start - 1)
					push(b, a, coms);
				else if ((*b)->place == end || (*b)->place == end + 1)
				{
					push(b, a, coms);
					rotate(a, coms);
				}
				else
					reverse(b, coms);
			}
		push(b, a, coms);
		--start;
		if ((*a)->place > (*a)->right->place)
		{
			swap(a, coms);
			--start;
		}
		if ((*a)->left->place == start)
			--start;
		while ((*a)->left->place == end || (*a)->left->left->place == end)
			++end;
	}
	while ((*a)->left->place < (*a)->right->place)
	{
		reverse(a, coms);
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
	}
}

void	sort_100(t_stack **a, t_stack **b, int size, int **coms)
{
	int pivot;
	int count;
	int check_p = 0;

	if (size == 2 && (*a)->place > (*a)->right->place)
		swap(a, coms);
	else if (size == 3)
		solve_3(a, coms);
	else if (size > 3)
	{
		pivot = find_lowest(*a, size) + size / 2 + size % 2;
		count = 0;
		while (count * 2 < size || check_p != 2)
		{
			if ((*a)->place < pivot)
			{
				push(a, b, coms);
				++count;
			}
			else if ((*a)->place == pivot)
			{
				push(a, b, coms);
				rotate(b, coms);
				++check_p;
			}
			else if ((*a)->place == pivot + 1)
			{
				push(a, b, coms);
				rotate(b, coms);
				++check_p;
			}
			else
				rotate(a, coms);
		}
		sort_100(a, b, size - count - 2, coms);
		reverse(b, coms);
		reverse(b, coms);
		push(b, a, coms);
		push(b, a, coms);
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
		sort_back(a, b, count, coms);
	}
}