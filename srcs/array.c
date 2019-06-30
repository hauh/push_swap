/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:00:23 by smorty            #+#    #+#             */
/*   Updated: 2019/07/01 00:25:09 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_number(char *s)
{
	long long	num;
	int			len;
	int			sign;

	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	num = 0;
	sign = (*s == '-' ? -1 : 1);
	if (*s == '-' || *s == '+')
		++s;
	if (*s < '0' || *s > '9')
		error();
	while (*s == '0')
		++s;
	len = 0;
	while (*s >= '0' && *s <= '9' && len <= 10)
	{
		num = num * 10 + (*s - '0');
		++len;
		++s;
	}
	num *= sign;
	if (*s || num != (int)num)
		error();
	return ((int)num);
}

static int	*get_array_single_arg(char **arg, int *size)
{
	int *arr;
	int i;

	if (!(arg = ft_strsplit(*arg, ' ')) || !*arg)
		return (NULL);
	i = 0;
	while (arg[i])
		++i;
	if (i > 1)
		arr = get_array(i, arg, size);
	else if ((arr = (int *)malloc(sizeof(int))))
		*arr = get_number(*arg);
	*size = i;
	while (i)
		free(arg[i--]);
	free(arg);
	return (arr);
}

int			*get_array(int argc, char **argv, int *size)
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
		*(arr + i++) = get_number(*argv++);
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

static int	get_median(int *begin, int *end, int *pivot)
{
	if (end - begin < 1)
		return (0);
	if (end - begin == 1)
	{
		if (*begin > *end)
		{
			*pivot = *begin;
			*begin = *end;
			*end = *pivot;
		}
		return (0);
	}
	*pivot = *(begin + (end - begin) / 2);
	if ((*pivot > *end && *end > *begin) || (*pivot < *end && *end < *begin))
		*pivot = *end;
	else if ((*pivot > *begin && *begin > *end) || (*pivot < *begin && *begin < *end))
		*pivot = *begin;
	return (1);
}

void		sort_array(int *begin, int *end)
{
	int pivot;
	int *left;
	int *right;
	int swp;

	if (!get_median(begin, end, &pivot))
		return ;
	left = begin;
	right = end;
	while (left <= right)
	{
		if (*left < pivot)
			++left;
		else if (*right > pivot)
			--right;
		else
		{
			swp = *left;
			*left++ = *right;
			*right-- = swp;
		}
	}
	sort_array(begin, right);
	sort_array(left - 1, end);
}
