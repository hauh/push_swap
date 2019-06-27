/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:43:58 by smorty            #+#    #+#             */
/*   Updated: 2019/06/27 18:57:34 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_size(t_stack *s)
{
	t_stack	*head;
	int		size;

	size = 0;
	if (s)
	{
		++size;
		head = s;
		s = s->right;
		while (s != head)
		{
			++size;
			s = s->right;
		}
	}
	return (size);
}

int		is_sorted(t_stack *s, int size)
{
	t_stack *r;

	r = s;
	r = r->right;
	--size;
	while (r != s && r->place > r->left->place)
	{
		r = r->right;
		--size;
	}
	if (size != 0)
		return (0);
	return (1);
}

int		find_lowest(t_stack *s, int size)
{
	int low;

	low = 0;
	if (s)
	{
		low = s->place;
		while (--size)
		{
			s = s->right;
			if (s->place < low)
				low = s->place;
		}
	}
	return (low);
}

int		find_highest(t_stack *s, int size)
{
	int high;

	high = 0;
	if (s)
	{
		high = s->place;
		while (--size)
		{
			s = s->right;
			if (s->place > high)
				high = s->place;
		}
	}
	return (high);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(-1);
}
