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
char *g_coms = "";

void	mark_stack(t_stack *a, int *arr, int size)
{
	int i = 1;

	while (size--)
	{
		while (a->n != *arr)
			a = a->right;
		a->place = i++;
		++arr;
	}
}

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		size;
	int		*arr;

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
	if (size <= 3)
		solve_3(&a);
	else if (size <= 5)
		solve_5(&a, &b, size);
	else
		split_a(&a, &b, 0, size);
	while (b)
		push(&b, &a);
	ft_printf("%s", g_coms);
	return (0);
}
