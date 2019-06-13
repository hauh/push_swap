/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:18:43 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 21:07:33 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int n)
{
	t_stack *st;

	st = (t_stack *)malloc(sizeof(t_stack));
	st->n = n;
	st->place = 0;
	st->head = 0;
	st->right = NULL;
	st->left = NULL;
	return (st);
}

t_stack	*store_stack(int argc, char **argv, int *size)
{
	t_stack *a;
	t_stack *head;

	head = new_stack(ft_atoi(*argv++));
	head->head = 1;
	head->ab = 'a';
	a = head;
	while (--argc)
	{
		a->right = new_stack(ft_atoi(*argv++));
		a->right->left = a;
		a->right->ab = 'a';
		a = a->right;
		++(*size);
	}
	a->right = head;
	head->left = a;
	return (head);
}

void	print_stack(t_stack *a, t_stack *b)
{
	ft_printf("-------------------\n");
	if (a)
	{
		ft_printf("%5d | ", a->n);
		a = a->right;
	}
	else
		ft_printf("      | ");
	if (b)
	{
		ft_printf("%5d", b->n);
		b = b->right;
	}
	ft_printf("\n");
	while ((a && !a->head) || (b && !b->head))
	{
		if (a && !a->head)
		{
			ft_printf("%5d | ", a->n);
			a = a->right;
		}
		else
			ft_printf("      | ");
		if (b && !b->head)
		{
			ft_printf("%5d",b->n);
			b = b->right;
		}
		ft_printf("\n");
	}
	ft_printf("moves: %d\n", g_count);
}