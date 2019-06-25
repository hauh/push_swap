/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:37:39 by smorty            #+#    #+#             */
/*   Updated: 2019/06/25 18:10:46 by smorty           ###   ########.fr       */
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

static int	split(t_stack **a, t_stack **b, int size, int **coms)
{
	int pivot;
	int pushed;
	int rotated;

	pivot = (*a)->ab == 'a' ? find_lowest(*a, size) : find_highest(*a, size);
	pivot += (*a)->ab == 'a' ? size / 2 : -(size / 2);
	pushed = 0;
	rotated = 0;
	while (size--)
	{
		if (((*a)->ab == 'a' && (*a)->place <= pivot) ||
			((*a)->ab == 'b' && (*a)->place >= pivot))
		{
			push(a, b, coms);
			(*b)->place == pivot ? rotate(b, coms) : ++pushed;
		}
		else
		{
			rotate(a, coms);
			++rotated;
		}
	}
	if (stack_size(*a) > rotated)
		while (rotated--)
			reverse(a, coms);
	return (pushed);
}

void		sort_500(t_stack **a, t_stack **b, int size, int **coms)
{
	int pushed;

	if (size == 2 && (((*a)->ab == 'a' && (*a)->place > (*a)->right->place)
		|| ((*a)->ab == 'b' && (*a)->place < (*a)->right->place)))
		swap(a, coms);
	else if (size == 3 && (*a)->ab == 'a')
		sort_3_ascending(a, coms);
	else if (size == 3 && (*a)->ab == 'b')
		sort_3_descending(a, coms);
	else if (size > 3)
	{
		pushed = split(a, b, size, coms);
		sort_500(a, b, size - pushed - 1, coms);
		reverse(b, coms);
		push(b, a, coms);
		sort_500(b, a, pushed, coms);
		while (pushed--)
			push(b, a, coms);
	}
}
