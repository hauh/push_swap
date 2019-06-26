/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:18:43 by smorty            #+#    #+#             */
/*   Updated: 2019/06/26 23:24:42 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int n)
{
	t_stack *st;

	st = (t_stack *)malloc(sizeof(t_stack));
	st->n = n;
	st->place = 0;
	st->right = NULL;
	st->left = NULL;
	return (st);
}

t_stack	*store_stack(int *arr, int size)
{
	t_stack *a;
	t_stack *head;

	head = new_stack(*arr++);
	head->ab = 'a';
	a = head;
	while (--size)
	{
		a->right = new_stack(*arr++);
		a->right->left = a;
		a->right->ab = 'a';
		a = a->right;
	}
	a->right = head;
	head->left = a;
	return (head);
}

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

void	free_stack(t_stack *s)
{
	while (s->right)
	{
		s = s->right;
		free(s->left);
		s->left = NULL;
	}
	free(s);
	s = NULL;
}
