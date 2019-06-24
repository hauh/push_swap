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

void	sort(t_stack **a, int size, int *coms)
{
	t_stack	*b;
	int		*p;

	p = coms;
	*p++ = 0;
	b = NULL;
	if (size <= 3)
		solve_3(a, &p);
	else if (size <= 5)
		solve_5_a(a, &b, size, &p);
	else if (size <= 100)
		sort_100(a, &b, size, &p);
	else
		sort_500(a, &b, size, &p);
	*p = -1;
	free(b);
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
	int		size;
	int		*arr;
	int		*coms;

	if (argc-- == 1)
		return (0);
	if (!check_args(argc, argv + 1) || !(arr = get_array(argc, argv + 1)))
	{
		ft_printf("Error\n");
		return (-1);
	}
	size = 1;
	a = store_stack(argc, argv + 1, &size);
	sort_array(arr, arr + size - 1);
	mark_stack(a, arr, size);
	coms = (int *)malloc(sizeof(int) * (size * size + 1));
	if (!is_sorted(a, size))
	{
		sort(&a, size, coms);
		optimize_coms(coms);
		print_coms(coms);
	}
	free(a);
	free(coms);
	return (0);
}
