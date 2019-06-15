/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:40:49 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 17:12:30 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_count = 0;

void	solve(t_stack **a, t_stack **b, int size, int *coms)
{
	int *p;

	p = coms;
	*p++ = 0;
	if (size <= 3)
		solve_3(a, &p);
	else if (size <= 5)
		solve_5_a(a, b, size, &p);
	else
		split_a(a, b, size, &p);
	while (*b)
		push(b, a, &p);
	*p = -1;
}

void	print_coms(int *coms)
{
	while (*coms != -1)
	{
		if (*coms == SA)
			ft_printf("sa\n");
		else if (*coms == PA)
			ft_printf("pa\n");
		else if (*coms == RA)
			ft_printf("ra\n");
		else if (*coms == RRA)
			ft_printf("rra\n");
		else if (*coms == SB)
			ft_printf("sb\n");
		else if (*coms == PB)
			ft_printf("pb\n");
		else if (*coms == RB)
			ft_printf("rb\n");
		else if (*coms == RRB)
			ft_printf("rrb\n");
		else if (*coms == RR)
			ft_printf("rr\n");
		else if (*coms == RRR)
			ft_printf("rrr\n");
		++coms;
	}
}

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		size;
	int		*arr;
	int		*coms;

	if (!check_args(argc - 1, argv + 1) || !(arr = get_array(argc - 1, argv + 1)))
	{
		ft_printf("Error\n");
		return (-1);
	}
	size = 1;
	a = store_stack(argc - 1, argv + 1, &size);
	b = NULL;
	sort_array(arr, arr + size - 1);
	mark_stack(a, arr, size);
	coms = (int *)malloc(sizeof(int) * (size * size + 1));
	solve(&a, &b, size, coms);
	print_stack(a, b);
//	print_coms(coms);
/*	int c = 0;
	int i = 0;
	while (coms[i] != -1)
	{
		if (coms[i] != 0)
			++c;
		i++;
	}
	ft_printf("coms %d ", c);*/
//	ft_printf("%d\n", g_count);
	optimize_coms(coms);
/*	print_stack(a, b);
	i = 0;
	c = 0;
	while (coms[i] != -1)
	{
		if (coms[i] != 0)
			++c;
		i++;
	}*/
//	print_coms(coms);
//	ft_printf("coms new %d\n", c);
	free(coms);
	return (0);
}
