/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:00:23 by smorty            #+#    #+#             */
/*   Updated: 2019/06/25 18:15:45 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*get_array_single_arg(char **arg, int *size)
{
	int *arr;
	int i;

	i = 0;
	if (!(arg = ft_strsplit(*arg, ' ')))
		return (NULL);
	while (arg[i])
		++i;
	if (i > 1)
		arr = get_array(i, arg, size);
	else if ((arr = (int *)malloc(sizeof(int))))
		*arr = ft_atoi(*arg);
	while (i)
		free(arg[i--]);
	free(arg);
	return (arr);
}

int		*get_array(int argc, char **argv, int *size)
{
	int *arr;
	int i;

	if (argc == 1)
		return (get_array_single_arg(argv, size));
	*size = argc;
	i = 0;
	if (!(arr = (int *)malloc(sizeof(int) * argc)))
		return (NULL);
	while (i < argc)
		*(arr + i++) = ft_atoi(*argv++);
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
