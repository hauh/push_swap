/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:15:20 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 23:11:04 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		where_to(t_stack *s, int place)
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

int stack_size(t_stack *a)
{
	int size;
	
	size = 0;
	if (a)
	{
		++size;
		a = a->right;
		while (!a->head)
		{
			++size;
			a = a->right;
		}
	}
	return (size);
}

int find_lowest(t_stack *a)
{
	int low;
	
	low = 0;
	if (a)
	{
		low = a->place;
		a = a->right;
		while (!a->head)
		{
			if (a->place < low)
				low = a->place;
			a = a->right;
		}
	}
	return (low);
}

int find_highest(t_stack *a)
{
	int high;
	
	high = 0;
	if (a)
	{
		high = a->place;
		a = a->right;
		while (!a->head)
		{
			if (a->place > high)
				high = a->place;
			a = a->right;
		}
	}
	return (high);
}

void	solve_a(t_stack **a, t_stack **b, int end, int size)
{
	int start;

	start = end - size + 1;
	while (*b && size-- > 0)
	{
		if (where_to(*b, end) > 0)
			while (*b && (*b)->place != end)
			{
				if (size > 1 && (*b)->place == end - 1)
					push(b, a);
				else if ((*b)->place == start)
				{
					push(b, a);
					rotate(a);
					--size;
					++start;
				}
				else
					reverse(b);
			}
		else
			while ((*b)->place != end)
			{
				if (size > 1 && (*b)->place == end - 1)
					push(b, a);
				else if ((*b)->place == start)
				{
					push(b, a);
					rotate(a);
					--size;
					++start;
				}
				else
					rotate(b);
			}
		push(b, a);
		--end;
		if ((*a)->place > (*a)->right->place)
		{
			swap(a);
			--end;
			--size;
		}
	}
	while ((*a)->left->place < (*a)->place)
		reverse(a);
}

void	solve_b(t_stack **a, t_stack **b, int size)
{
	int start;
	int end;

	start = find_highest(*a) + 1;
	end = start + size - 1;
	while (*b && size-- > 0)
	{
		if (where_to(*b, start) > 0)
			while (*b && (*b)->place != start)
			{
				if (size > 1 && (*b)->place == start + 1)
					push(b, a);
				else if ((*b)->place == end)
				{
					push(b, a);
					rotate(a);
					--size;
					--end;
				}
				else
					reverse(b);
			}
		else
			while ((*b)->place != start)
			{
				if (size > 1 && (*b)->place == start + 1)
					push(b, a);
				else if ((*b)->place == end)
				{
					push(b, a);
					rotate(a);
					--size;
					--end;
				}
				else
					rotate(b);
			}
		push(b, a);
		++start;
		if ((*a)->place < (*a)->right->place)
		{
			swap(a);
			++start;
			--size;
		}
	}
	while ((*a)->left->place > (*a)->place)
		reverse(a);
}

void	split_b(t_stack **a, t_stack **b, int size)
{
	int median;
	int s;

	median = find_highest(*a) - size / 2 - size % 2;
	s = size / 2 + size % 2;
	if (size > 3)
	{
		while (s)
		{
			if ((*a)->place > median)
			{
				push(a, b);
				--s;
			}
			else
				rotate(a);
		}
		split_b(a, b, size / 2);
		solve_b(a, b, size / 2 + size % 2);
	}
	else
		solve_3(a);
}

void	split_a(t_stack **a, t_stack **b, int median, int size)
{
	int s;

	s = size / 2 + size % 2;
	median += s;
	if (size > 3)
	{
		while (s)
		{
			if ((*a)->place <= median)
			{
				push(a, b);
				--s;
			}
			else
				rotate(a);
		}
		split_a(a, b, median, size / 2);
		if (stack_size(*a) != stack_size(*b))
			solve_a(a, b, median, size / 2 + size % 2);
		else
			split_b(b, a, size / 2);
	}
	else
		solve_3(a);
}
