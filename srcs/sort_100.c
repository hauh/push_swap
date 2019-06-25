/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:15:20 by smorty            #+#    #+#             */
/*   Updated: 2019/06/26 00:04:40 by smorty           ###   ########.fr       */
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
/*
static void	get_next_element(t_stack **a, t_stack **b, int start, int end)
{
	while ((*b)->place != start)
	{
		if ((*b)->place == start - 1)
			push(b, a, coms);
		else if ((*b)->place == end || (*b)->place == end + 1)
		{
			push(b, a, coms);
			rotate(a, coms);
		}
		else if (where_to(*b, start) >= 0)

	}
}*/

static void	sort_back(t_stack **a, t_stack **b, int size, int **coms)
{
	int start;
	int end;
	int dir;
	int t;

	start = find_highest(*b, size);
	end = find_lowest(*b, size);
	t = 0;
	while (end <= start)
	{
		if (*(*coms - 1) != RB && *(*coms - 1) != RRB && start - end > 1)
			dir = (where_to(*b, start) < 0 ? RRB : RB);
		while ((*b)->place != start)
		{
			if ((*b)->place == start - 1)
				push(b, a, coms);
			else if ((*b)->place == end)
			{
				end += 1 + t;
				t = 0;
				push(b, a, coms);
				rotate(a, coms);
			}
			else if ((*b)->place == end + 1)
			{
				t = 1;
				push(b, a, coms);
				rotate(a, coms);
			}
			else if (where_to(*b, start) >= 0)
				rotate(b, coms);
			else
				reverse(b, coms);
		}
		push(b, a, coms);
		--start;
		if ((*a)->place > (*a)->right->place)
		{
			--start;
			swap(a, coms);
		}
        if ((*a)->left->place == start)
            --start;
//		while ((*a)->left->place == end || (*a)->left->left->place == end)
//			++end;
	}
//		print_stacks(*a, *b, "   ", 11);
/*		while (end <= start)
		{
		while ((*b)->place != start)// && (*b)->place != start - 1)
		{
			if ((*b)->place == start - 1)
				push(b, a, coms);
			if ((*b)->place == end || (*b)->place == end + 1)
			{
				push(b, a, coms);
				rotate(a, coms);
			}
			else if (where_to(*b, start) < 0)
				reverse(b, coms);
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
        if ((*a)->left->place == start)
            --start;
        while ((*a)->left->place == end || (*a)->left->left->place == end)
            ++end;
		}
		if (where_to(*b, start) >= 0)
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
    }*/
	while ((*a)->left->place < (*a)->right->place)
	{
		reverse(a, coms);
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
	}
}

void		sort_100(t_stack **a, t_stack **b, int size, int **coms)
{
	int pivot;
	int count;

	if (size < 4)
		sort_3(a, coms);
	else
	{
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
		sort_100(a, b, size - count, coms);
		reverse(b, coms);
		reverse(b, coms);
		push(b, a, coms);
		push(b, a, coms);
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
		sort_back(a, b, count - 2, coms);
	}
}
