/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:37:39 by smorty            #+#    #+#             */
/*   Updated: 2019/06/17 23:57:14 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

static void	sort_5_descending(t_stack **a, t_stack **b, int size, int **coms)
{
	int start;
	int end;
	int r;

	start = find_lowest(*a, size) + size - 1;
	end = size;
	r = 0;
	while (end > 2)
	{
		if (where_to(*a, start) > 0)
			while ((*a)->place != start)
			{
				reverse(a, coms);
				--r;
			}
		else
			while ((*a)->place != start)
			{
				rotate(a, coms);
				++r;
			}
		push(a, b, coms);
		--start;
		--end;
	}
	while (r < 0)
	{
		rotate(a, coms);
		++r;
	}
	while (r > 0)
	{
		reverse(a, coms);
		--r;
	}
	if (end == 2 && (*a)->place < (*a)->right->place)
		swap(a, coms);
	while (end < size)
	{
		push(b, a, coms);
		++end;
	}
}

static void	sort_5_ascending(t_stack **a, t_stack **b, int size, int **coms)
{
	int start;
	int end;
	int r;

	start = find_lowest(*a, size);
	end = size;
	r = 0;
	while (end > 2)
	{
		if (where_to(*a, start) > 0)
			while ((*a)->place != start)
			{
				reverse(a, coms);
				--r;
			}
		else
			while ((*a)->place != start)
			{
				rotate(a, coms);
				++r;
			}
		push(a, b, coms);
		++start;
		--end;
	}
	while (r < 0)
	{
		rotate(a, coms);
		++r;
	}
	while (r > 0)
	{
		reverse(a, coms);
		--r;
	}
	if (end == 2 && (*a)->place > (*a)->right->place)
		swap(a, coms);
	while (end < size)
	{
		push(b, a, coms);
		++end;
	}
}

void    quicksort_descending(t_stack **a, t_stack **b, int size, int **coms)
{
	int pivot;
	int r;
	int size_a;

	if (size <= 5)
		sort_5_descending(a, b, size, coms);
	else
	{
		pivot = find_highest(*a, size) - size / 2;
		size_a = 0;
		r = 0;
		while (size_a < size / 2)
		{
			if ((*a)->place > pivot)
			{
				push(a, b, coms);
				++size_a;
			}
			else
			{
				++r;
				rotate(a, coms);
			}
		}
		if (stack_size(*a) != size)
			while (r--)
				reverse(a, coms);
		quicksort_descending(a, b, size - size_a, coms);
		quicksort_ascending(b, a, size_a, coms);
		while (size_a--)
			push(b, a, coms);
	}
}

void    quicksort_ascending(t_stack **a, t_stack **b, int size, int **coms)
{
	int pivot;
	int r;
	int size_b;

	if (size <= 5)
		sort_5_ascending(a, b, size, coms);
	else
	{
		pivot = find_lowest(*a, size) + size / 2;
		size_b = 0;
		r = 0;
		while (size_b < size / 2)
		{
			if ((*a)->place < pivot)
			{
				push(a, b, coms);
				++size_b;
			}
			else
			{
				++r;
				rotate(a, coms);
			}
		}
		if (stack_size(*a) != size)
			while (r--)
				reverse(a, coms);
		quicksort_ascending(a, b, size - size_b, coms);
		quicksort_descending(b, a, size_b, coms);
		while (size_b--)
			push(b, a, coms);
	}
}
