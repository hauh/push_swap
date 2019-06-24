/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:00:23 by smorty            #+#    #+#             */
/*   Updated: 2019/06/24 23:59:29 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_stack(t_stack *a, int *arr, int size)
{
	int i;
	int *arr0;

	i = 1;
	arr0 = arr;
	while (size--)
	{
		while (a->n != *arr)
			a = a->right;
		a->place = i++;
		++arr;
	}
	free(arr0);
}

void	sort_array(int *begin, int *end)
{
	int	*left;
	int	*right;
	int	pivot;
	int swp;

	left = begin;
	right = end;
	pivot = (*left + *right) / 2;
	while (left <= right)
	{
        while (*left <= pivot)
           ++left;
        while (*right > pivot)
           --right;
		if (left < right)
		{
			swp = *left;
			*left = *right;
			*right = swp;
		}
	}
	if (begin < right && right != end)
		sort_array(begin, right);
	if (end > left && left != begin)
		sort_array(left, end);
}

static int *get_array_from_single_arg(char *arg)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = 1;
	while (*(arg + i))
	{
		while (*(arg + i) == ' ')
			++i;
		++j;
		++i;
	}
	if (!(arr = (int *)malloc(sizeof(int) * j)))
		return (NULL);
		i = 0;
		j = 0;
	while (*arg)
	{
		*(arr + i) = ft_atoi(&*arg);
		while (*arg && *arg != ' ')
			++arg;
		++i;
	}
	i = j;
//	while 
	return (arr);
}

int		*get_array(int argc, char **argv)
{
	int *arr;
	int i;

	if (argc == 1)
		return (get_array_from_single_arg(*argv));
	if (!(arr = (int *)malloc(sizeof(int) * argc)))
		return (NULL);
	i = 0;
	while (i < argc)
	{
		*(arr + i++) = ft_atoi(*argv++);
	}
	while (argc--)
	{
		i = argc;
		while (i--)
		{
			if (*(arr + argc) == *(arr + i))
			{
				free(arr);
				return (NULL);
			}
		}
	}
	return (arr);
}
