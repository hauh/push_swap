/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:15:20 by smorty            #+#    #+#             */
/*   Updated: 2019/06/17 23:44:15 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		where_to(t_stack *s, int place)
{
	t_stack	*rotate;
	int		direction;

	rotate = s;
	direction = 0;
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

void	solve_b(t_stack **a, t_stack **b, int size, int **coms)
{
	int start;
	int end;

	start = find_lowest(*b, size);
	end = start + size - 1;
	while (start <= end)
	{
		if (where_to(*b, start) > 0)
			while ((*b)->place != start)
			{
				if ((*b)->place == start + 1 && start != end)
					push(b, a, coms);
				else if ((*b)->place == end)
				{
					while ((*b)->place == end && (*b)->place != start)
					{
						push(b, a, coms);
						rotate(a, coms);
						--end;
					}
				}
				else
					reverse(b, coms);
			}
		else
			while ((*b)->place != start)
			{
				if ((*b)->place == start + 1 && start != end)
					push(b, a, coms);
				else if ((*b)->place == end)
				{
					while ((*b)->place == end && end > start)
					{
						push(b, a, coms);
						rotate(a, coms);
						--end;
					}
				}
				else
					rotate(b, coms);
			}
		push(b, a, coms);
		++start;
		if ((*a)->place < (*a)->right->place)
		{
			swap(a, coms);
			++start;
		}
	}
	while ((*a)->left->place > (*a)->place)
		reverse(a, coms);
}

void	split_b(t_stack **a, t_stack **b, int size, int **coms)
{
	int s;
	int median;

	s = size / 2;
	median = size / 2 + size % 2;
	if (size > 5)
	{
		while (s)
		{
			if ((*a)->place > median)
			{
				push(a, b, coms);
				--s;
			}
			else
				rotate(a, coms);
		}
		split_b(a, b, size / 2 + size % 2, coms);
		solve_b(a, b, size / 2, coms);
	}
	else if (size < 4)
		solve_3(a, coms);
	else
		solve_5_b(a, b, size, coms);	
}

void	solve_a(t_stack **a, t_stack **b, int size, int **coms)
{
	int start;
	int end;

	start = find_highest(*b, size);
	end = start - size + 1;
	while (start >= end)
	{
		if (where_to(*b, start) > 0)
			while ((*b)->place != start)
			{
				if ((*b)->place == start - 1 && start != end)
					push(b, a, coms);
				else if ((*b)->place == end)
				{
					while ((*b)->place == end && end < start)
					{
						push(b, a, coms);
						rotate(a, coms);
						++end;
					}
				}
				else
					reverse(b, coms);
			}
		else
			while ((*b)->place != start)
			{
				if ((*b)->place == start - 1 && start != end)
					push(b, a, coms);
				else if ((*b)->place == end)
				{
					while ((*b)->place == end && (*b)->place != start)
					{
						push(b, a, coms);
						rotate(a, coms);
						++end;
					}
				}
				else
					rotate(b, coms);
			}
		push(b, a, coms);
		--start;
		if ((*a)->place > (*a)->right->place)
		{
			swap(a, coms);
			--start;
		}
	}
	while ((*a)->left->place < (*a)->place)
		reverse(a, coms);
}

void	split_a(t_stack **a, t_stack **b, int size, int **coms)
{
	int s;
	int median;
	int flag = 0;

	if (!*b)
		flag = 1;
	s = size / 2;
	median = find_lowest(*a, size) + s;
	if (size > 5)
	{
		while (s)
		{
			if ((*a)->place < median)
			{
				push(a, b, coms);
				--s;
				if ((*b)->place < median / 4 && (*b)->place != (*b)->right->place)
					rotate(b, coms);
			}
			else
				rotate(a, coms);
		}
		split_a(a, b, size / 2 + size % 2, coms);
		print_stack(*a, *b);
		if (stack_size(*a) != stack_size(*b))
			solve_a(a, b, size / 2, coms);
		else
			split_b(b, a, size / 2, coms);
	}
	else if (size < 4)
		solve_3(a, coms);
	else
		solve_5_a(a, b, size, coms);
}
