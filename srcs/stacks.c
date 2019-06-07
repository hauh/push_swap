/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:18:43 by smorty            #+#    #+#             */
/*   Updated: 2019/06/07 20:53:02 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int n)
{
	t_stack *st;

	st = (t_stack *)malloc(sizeof(t_stack));
	st->n = n;
	st->next = NULL;
	return (st);
}

t_stack	*store_stack(int argc, char **argv)
{
	t_stack *a;

	if (argc)
	{
		a = new_stack(ft_atoi(*argv));
		a->next = store_stack(argc - 1, argv + 1);
	}
	else
		a = NULL;
	return (a);
}
