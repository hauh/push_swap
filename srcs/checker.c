/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:17:48 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 23:14:50 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *g_coms = NULL;
int	g_count = 0;

void	checker(t_stack **a)
{
	t_stack	*b;
	char	*coms;

	b = NULL;
	while (get_next_line(0, &coms))
	{
//		ft_printf("%s ", coms);
		if (ft_strequ(coms, "sa"))
			swap(a);
		else if (ft_strequ(coms, "sb"))
			swap(&b);
		else if (ft_strequ(coms, "ra"))
			rotate(a);
		else if (ft_strequ(coms, "rb"))
			rotate(&b);
		else if (ft_strequ(coms, "rra"))
			reverse(a);
		else if (ft_strequ(coms, "rrb"))
			reverse(&b);
		else if (ft_strequ(coms, "pa"))
			push(&b, a);
		else if (ft_strequ(coms, "pb"))
			push(a, &b);
		else
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		free(coms);
	}
//	ft_printf("\n", coms);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	int		size;

	if (argc < 2)
		return (-1);
	size = 1;
	a = store_stack(argc - 1, argv + 1, &size);
//	print_stack(a, b);
	checker(&a);
	ft_printf(is_sorted(a, size) ? "OK\n" : "KO\n");
//	print_stack(a, b);
	return (0);
}