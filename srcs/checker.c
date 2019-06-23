/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:17:48 by smorty            #+#    #+#             */
/*   Updated: 2019/06/23 23:54:21 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack **a)
{
	t_stack	*b;
	char	*com;

	b = NULL;
	print_stacks(*a, b, "   ", 2);
	while (get_next_line(0, &com))
	{
		if (ft_strequ(com, "sa"))
			swap(a, NULL);
		else if (ft_strequ(com, "sb"))
			swap(&b, NULL);
		else if (ft_strequ(com, "ss"))
		{
			swap(a, NULL);
			swap(&b, NULL);
		}
		else if (ft_strequ(com, "ra"))
			rotate(a, NULL);
		else if (ft_strequ(com, "rb"))
			rotate(&b, NULL);
		else if (ft_strequ(com, "rr"))
		{
			rotate(a, NULL);
			rotate(&b, NULL);
		}
		else if (ft_strequ(com, "rra"))
			reverse(a, NULL);
		else if (ft_strequ(com, "rrb"))
			reverse(&b, NULL);
		else if (ft_strequ(com, "rrr"))
		{
			reverse(a, NULL);
			reverse(&b, NULL);
		}
		else if (ft_strequ(com, "pa"))
			push(&b, a, NULL);
		else if (ft_strequ(com, "pb"))
			push(a, &b, NULL);
		else
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		print_stacks(*a, b, com, 2);
		free(com);
	}
}

int	main(int argc, char **argv)
{
	t_stack *a;
	int		size;

	if (argc < 2)
		return (-1);
	size = 1;
	a = store_stack(argc - 1, argv + 1, &size);
	checker(&a);
	ft_printf("\e[u");
	ft_printf(is_sorted(a, size) ? "OK\n" : "KO\n");
	return (0);
}