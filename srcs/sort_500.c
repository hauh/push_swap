/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:37:39 by smorty            #+#    #+#             */
/*   Updated: 2019/07/01 00:28:28 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** set 1 = 123, set 2 = 132, set 3 = 213, set 4 = 231, set 5 = 312, set 6 = 321
*/

static void	sort_3_1(t_stack **s, int **ops, int set)
{
	if ((set == 6 && (*s)->ab == 'a') || (set == 1 && (*s)->ab == 'b')) //321 //123
		if (stack_size(*s) == 3)
		{
			rotate(s, ops);
			swap(s, ops);
		}
		else
		{
			swap(s, ops);
			rotate(s, ops);
			swap(s, ops);
			reverse(s, ops);
			swap(s, ops);
		}
	else if ((set == 2 && (*s)->ab == 'a') || (set == 5 && (*s)->ab == 'b')) //132 //312
		if (stack_size(*s) == 3)
		{
			swap(s, ops);
			rotate(s, ops);
		}
		else
		{
			rotate(s, ops);
			swap(s, ops);
			reverse(s, ops);
		}
	else if ((set == 5 && (*s)->ab == 'a') || (set == 2 && (*s)->ab == 'b')) //312 //132
		if (stack_size(*s) == 3)
			rotate(s, ops);
		else
		{
			swap(s, ops);
			rotate(s, ops);
			swap(s, ops);
			reverse(s, ops);
		}
	else if ((set == 4 && (*s)->ab == 'a') || (set == 3 && (*s)->ab == 'b')) //231 //213
		if (stack_size(*s) == 3)
			reverse(s, ops);
		else
		{
			rotate(s, ops);
			swap(s, ops);
			reverse(s, ops);
			swap(s, ops);
		}
	else if ((set == 3 && (*s)->ab == 'a') || (set == 4 && (*s)->ab == 'b')) //213 //231
		swap(s, ops);
}

void	sort_3_ascending(t_stack **s, int **ops)
{
	int set;
	int one;
	int two;
	int three;

	set = 0;
	one = (*s)->place;
	two = (*s)->right->place;
	three = (*s)->right->right->place;
	if (one < two && two < three) //123
		set = 1;
	else if (one < three && three < two) //132
		set = 2;
	else if (one > two && three > one) //213
		set = 3;
	else if (one > three && two > one) //231
		set = 4;
	else if (one > three && three > two) //312
		set = 5;
	else if (one > two && two > three) //321
		set = 6;
	sort_3_1(s, ops, set);// : sort_3_2(s, ops, set);
}

static int	split(t_stack **a, t_stack **b, int size, int **ops)
{
	int pivot;
	int pushed;
	int rotated;

	pivot = (*a)->ab == 'a' ? find_lowest(*a, size) : find_highest(*a, size);
	pivot += (*a)->ab == 'a' ? size / 2 : -(size / 2);
	pushed = 0;
	rotated = 0;
	while (size--)
		if (((*a)->ab == 'a' && (*a)->place <= pivot) ||
			((*a)->ab == 'b' && (*a)->place >= pivot))
		{
			push(a, b, ops);
			(*b)->place == pivot ? rotate(b, ops) : ++pushed;
		}
		else
		{
			rotate(a, ops);
			++rotated;
		}
	if (stack_size(*a) > rotated)
		while (rotated--)
			reverse(a, ops);
	return (pushed);
}

void		sort_500(t_stack **a, t_stack **b, int size, int **ops)
{
	int pushed;

	if (size == 2 && (((*a)->ab == 'a' && (*a)->place > (*a)->right->place)
		|| ((*a)->ab == 'b' && (*a)->place < (*a)->right->place)))
		swap(a, ops);
	else if (size == 3)
//		stack_size(*a) == 3 ? sort_3(a, ops) : sort_3_ascending(a, ops);
//	else if (size == 3 && (*a)->ab == 'b')
		sort_3_ascending(a, ops);
	else if (size > 3)
	{
		pushed = split(a, b, size, ops);
		sort_500(a, b, size - pushed - 1, ops);
		reverse(b, ops);
		push(b, a, ops);
		sort_500(b, a, pushed, ops);
		while (pushed--)
			push(b, a, ops);
	}
}
