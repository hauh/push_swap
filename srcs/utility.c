/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:43:58 by smorty            #+#    #+#             */
/*   Updated: 2019/06/17 23:43:45 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	char *s;

	if (argc < 1)
		return (0);
	while (argc--)
	{
		s = *argv++;
		if ((*s < '0' || *s > '9') && *s != '-' && *s != '+')
			return (0);
		++s;
		while (*s)
		{
			if (*s < '0' || *s > '9')
				return (0);
			++s;
		}
	}
	return (1);
}

int		is_sorted(t_stack *s, int size)
{
	t_stack *r;

	r = s;
	r = r->right;
	--size;
	while (r != s && r->n > r->left->n)
	{
		r = r->right;
		--size;
	}
	if (size != 0)
		return (0);
	return (1);
}

int find_lowest(t_stack *a, int size)
{
	int low;
	
	low = 0;
	if (a)
	{
		low = a->place;
		while (--size)
		{
			a = a->right;
			if (a->place < low)
				low = a->place;
		}
	}
	return (low);
}

int find_highest(t_stack *a, int size)
{
	int high;
	
	high = 0;
	if (a)
	{
		high = a->place;
		while (--size)
		{
			a = a->right;
			if (a->place > high)
				high = a->place;
		}
	}
	return (high);
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
