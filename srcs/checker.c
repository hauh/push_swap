/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:17:48 by smorty            #+#    #+#             */
/*   Updated: 2019/06/22 22:28:36 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_count = 0;

void	checker(t_stack **a)
{
	t_stack	*b;
	char	*coms;
	int count = 0;

	b = NULL;
	while (get_next_line(0, &coms))
	{
//		ft_printf("%s ", coms);
		if (ft_strequ(coms, "sa"))
			swap(a, NULL);
		else if (ft_strequ(coms, "sb"))
			swap(&b, NULL);
		else if (ft_strequ(coms, "ss"))
		{
			swap(a, NULL);
			swap(&b, NULL);
		}
		else if (ft_strequ(coms, "ra"))
			rotate(a, NULL);
		else if (ft_strequ(coms, "rb"))
			rotate(&b, NULL);
		else if (ft_strequ(coms, "rr"))
		{
			rotate(a, NULL);
			rotate(&b, NULL);
		}
		else if (ft_strequ(coms, "rra"))
			reverse(a, NULL);
		else if (ft_strequ(coms, "rrb"))
			reverse(&b, NULL);
		else if (ft_strequ(coms, "rrr"))
		{
			reverse(a, NULL);
			reverse(&b, NULL);
		}
		else if (ft_strequ(coms, "pa"))
			push(&b, a, NULL);
		else if (ft_strequ(coms, "pb"))
			push(a, &b, NULL);
		else
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		free(coms);
		++count;
	}
//	print_stack(*a, b);
//	ft_printf("moves %d\n", count);
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
	ft_printf(is_sorted(a, size) ? "OK\n" : "KO\n");
	return (0);
}