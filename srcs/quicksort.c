/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:37:39 by smorty            #+#    #+#             */
/*   Updated: 2019/06/22 22:48:15 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void		sort_3_ascending(t_stack **a, int **coms)
{
    int one;
    int two;
    int three;

    one = (*a)->place;
    two = (*a)->right->place;
    three = (*a)->right->right->place;
    if (one > two && one > three && two < three)
        if (stack_size(*a) == 3)
            swap(a, coms);
        else
        {
            swap(a, coms);
            rotate(a, coms);
            swap(a, coms);
            reverse(a, coms);
        }
    else if (one > two && one > three && two > three)
        if (stack_size(*a) == 3)
        {
            rotate(a, coms);
            swap(a, coms);
        }
        else
        {
            swap(a, coms);
            rotate(a, coms);
            swap(a, coms);
            reverse(a, coms);
            swap(a, coms);
        }
    else if (two > one && two > three && one < three)
        if (stack_size(*a) == 3)
        {
            reverse(a, coms);
            swap(a, coms);
        }
        else
        {
            rotate(a, coms);
            swap(a, coms);
            reverse(a, coms);
        }
    else if (two > one && two > three && one > three)
        if (stack_size(*a) == 3)
            reverse(a, coms);
        else
        {
            rotate(a, coms);
            swap(a, coms);
            reverse(a, coms);
            swap(a, coms);
        }
    else if (three > one && three > two && one > two)
        swap(a, coms);
}

void            sort_3_descending(t_stack **a, int **coms)
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
            reverse(a, coms);
            swap(a, coms);
        }
        else
        {
            rotate(a, coms);
            swap(a, coms);
            reverse(a, coms);
        }
    else if (two > one && two > three && one < three)
        if (stack_size(*a) == 3)
            rotate(a, coms);
        else
        {
            swap(a, coms);
            rotate(a ,coms);
            swap(a, coms);
            reverse(a, coms);
        }
    else if (two > one && two > three && one > three)
        swap(a, coms);
    else if (three > one && three > two && one > two)
        if (stack_size(*a) == 3)
            reverse(a, coms);
        else
        {
            rotate(a, coms);
            swap(a, coms);
            reverse(a, coms);
            swap(a, coms);
        }
    else if (three > one && three > two && one < two)
    {
        if (stack_size(*a) == 3)
        {
            swap(a, coms);
            reverse(a, coms);
        }
        else
        {
            swap(a, coms);
            rotate(a, coms);
            swap(a, coms);
            reverse(a, coms);
            swap(a, coms);
        }
    }
}

/*static void sort_3_ascending(t_stack **a, t_stack **b, int size, int **coms)
{
	while (!is_sorted(a, 3))
	{
		if ((*a)->place > (*a)->right->place)
			swap(a, coms);
		else if ((*a)->right->place > (*a)->right->right->place)
		{
			rotate(a, coms);
			swap(a, coms);
			reverse(a, coms);
		}
		else if ((*a)->place > (*a)->right->right->place)
		{
			push(a, b, coms);
			rotate(a, coms);
			push(a, b, coms);
			
		}
}*/
/*
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
}*/
/*
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
}*/

void    quicksort_descending(t_stack **a, t_stack **b, int size, int **coms)
{
	int pivot;
	int r;
	int size_a;
	int	check_p = 0;

	if (size == 2 && (*a)->place < (*a)->right->place)
		swap(a, coms);
	else if (size == 3)
		sort_3_descending(a, coms);

//	if (size <= 5)
//		sort_5_descending(a, b, size, coms);
	else if (size > 3)
	{
		pivot = find_highest(*a, size) - size / 2;
		size_a = 0;
		r = 0;
//		while (size_a < size / 2 || !check_p)
		check_p = size;
		while (check_p--)
		{
			if ((*a)->place == pivot)
			{
				push(a, b, coms);
				rotate(b, coms);
//				check_p = 1;
			}
			if ((*a)->place > pivot)
			{
				++size_a;
				push(a, b, coms);
			}
			else
			{
				++r;
				rotate(a, coms);
			}
		}
		if (stack_size(*a) > r)
			while (r--)
				reverse(a, coms);
		quicksort_descending(a, b, size - size_a - 1, coms);
		reverse(b, coms);
		push(b, a, coms);
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
	int check = 0;

//	ft_printf("size %d\n", size);
	if (size == 2 && (*a)->place > (*a)->right->place)
		swap(a, coms);
	else if (size == 3)
		sort_3_ascending(a, coms);
//	if (size <= 5)
//		sort_5_ascending(a, b, size, coms);
	else if (size > 3)
	{
		pivot = find_lowest(*a, size) + size / 2;
		size_b = 0;
		r = 0;
//		while (size_b < size / 2) || !check)
		check = size;
		while (check--)
		{
			if (*a && (*a)->place == pivot)
			{
				push(a, b, coms);
				rotate(b, coms);
//				check = 1;
			}
			else if (*a && (*a)->place < pivot)
			{
				++size_b;
				push(a, b, coms);
			}
			else
			{
				++r;
				rotate(a, coms);
			}
		}
		if (stack_size(*a) > r)
			while (r--)
				reverse(a, coms);
		quicksort_ascending(a, b, size - size_b - 1, coms);
		reverse(b, coms);
		push(b, a, coms);
		quicksort_descending(b, a, size_b, coms);
		while (size_b--)
			push(b, a, coms);
	}
}
