/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:17:48 by smorty            #+#    #+#             */
/*   Updated: 2019/06/28 00:28:35 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack **a, int flag)
{
	t_stack	*b;
	char	*com;

	b = NULL;
	if (flag)
		print_stacks(*a, b, "   ", flag);
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
			error();
		if (flag)
			print_stacks(*a, b, com, flag);
		free(com);
	}
}

int	get_flag(char **argv)
{
	int flag;

	if (**argv != '-' || (*(*argv + 1) > '0' && *(*argv + 1) < '9'))
		return (0);
	if (*(*argv + 1) == 'n')
		flag = 10 + (*(*argv + 2) ? *(*argv + 2) - '0' : 0);
	else if (*(*argv + 1) == 'v')
		flag = 20 + (*(*argv + 2) ? *(*argv + 2) - '0' : 0);
	else
	{
//		usage();
		exit(0);
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	int		*arr;
	int		size;
	int		flag;

	if (argc-- < 2)
		return (0);
	if ((flag = get_flag(++argv)) > 0)
	{
		++argv;
		--argc;
	}
	if (!(arr = get_array(argc, argv, &size)))
		error();
	a = store_stack(arr, size);
	sort_array(arr, arr + size - 1);
	mark_stack(a, arr, size);
	checker(&a, flag);
	ft_printf(a && is_sorted(a, size) ? "OK\n" : "KO\n");
	free(arr);
	free(a);
	return (0);
}