/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:30 by smorty            #+#    #+#             */
/*   Updated: 2019/06/07 20:25:04 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **st)
{
	t_stack *tmp;

	if (*st && (*st)->next)
	{
		tmp = (*st)->next;
		(*st)->next = tmp->next;
		tmp->next = *st;
		*st = tmp;
	}
}

void	push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}

void	rotate(t_stack **st)
{
	t_stack *tmp;

	if (*st && (*st)->next)
	{
		tmp = *st;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *st;
		tmp = *st;
		*st = (*st)->next;
		tmp->next = NULL;
	}
}

void	reverse(t_stack **st)
{
	t_stack *tmp;

	if (*st && (*st)->next)
	{
		tmp = *st;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *st;
		*st = tmp->next;
		tmp->next = NULL;
	}
}
