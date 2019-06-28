/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:59:30 by smorty            #+#    #+#             */
/*   Updated: 2019/06/28 22:43:25 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, int size, int *ops)
{
	t_stack	*b;
	int		*p;

	p = ops;
	*p++ = 0;
	b = NULL;
	if (size <= 3)
		sort_3(a, &p);
	else if (size <= 5)
		sort_5(a, &b, size, &p);
	else if (size <= 100)
		sort_100(a, &b, size, &p);
	else
		sort_500(a, &b, size, &p);
	*p = -1;
	while (b)
		push(&b, a, NULL);
}

void	print_ops(int *ops)
{
	while (*ops++ != -1)
	{
		if (*ops == SA)
			ft_printf("sa\n");
		else if (*ops == PA)
			ft_printf("pa\n");
		else if (*ops == RA)
			ft_printf("ra\n");
		else if (*ops == RRA)
			ft_printf("rra\n");
		else if (*ops == SB)
			ft_printf("sb\n");
		else if (*ops == PB)
			ft_printf("pb\n");
		else if (*ops == RB)
			ft_printf("rb\n");
		else if (*ops == RRB)
			ft_printf("rrb\n");
		else if (*ops == SS)
			ft_printf("ss\n");
		else if (*ops == RR)
			ft_printf("rr\n");
		else if (*ops == RRR)
			ft_printf("rrr\n");
	}
}

int		main(int argc, char **argv)
{
	t_stack *a;
	int		size;
	int		*arr;
	int		*ops;

	if (argc-- < 2)
		return (0);
	++argv;
	if (!(arr = get_array(argc, argv, &size)))
		error();
	a = store_stack(arr, size);
	sort_array(arr, arr + size - 1);
	mark_stack(a, arr, size);
	ops = (int *)malloc(sizeof(int) * (size * size + 1));
	if (!is_sorted(a, size))
	{
		sort(&a, size, ops);
		optimize_ops(ops);
		print_ops(ops);
	}
	free_stack(a, size);
	free(arr);
	free(ops);
	return (0);
}
