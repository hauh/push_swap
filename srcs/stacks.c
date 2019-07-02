/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:18:43 by smorty            #+#    #+#             */
/*   Updated: 2019/07/02 23:41:39 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(int n)
{
	t_stack *s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->n = n;
	s->place = 0;
	s->right = NULL;
	s->left = NULL;
	return (s);
}

t_stack			*store_stack(int *arr, int size)
{
	t_stack *s;
	t_stack *head;

	s = new_stack(*arr++);
	s->ab = 'a';
	head = s;
	while (--size)
	{
		s->right = new_stack(*arr++);
		s->right->left = s;
		s->right->ab = 'a';
		s = s->right;
	}
	s->right = head;
	head->left = s;
	return (head);
}

void			mark_stack(t_stack *a, int *arr, int size)
{
	int i;

	i = 1;
	while (size--)
	{
		while (a->n != *arr)
			a = a->right;
		a->place = i++;
		++arr;
	}
}

void			free_stack(t_stack *s, int size)
{
	while (--size)
	{
		s = s->right;
		free(s->left);
	}
	free(s);
}
