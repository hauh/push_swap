/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:43:58 by smorty            #+#    #+#             */
/*   Updated: 2019/06/25 19:19:29 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_single_arg(char *arg)
{
	while (*arg)
	{
		if ((*arg < '0' || *arg > '9') && *arg != '-' && *arg != '+')
			return (0);
		++arg;
		while (*arg && *arg != ' ')
		{
			if (*arg < '0' || *arg > '9')
				return (0);
			++arg;
		}
		if (*arg)
			++arg;
	}
	return (1);
}

int			check_args(int argc, char **argv)
{
	char *s;

	if (!argc)
		return (0);
	if (argc == 1)
		return (check_single_arg(*argv));
	while (argc--)
	{
		s = *argv++;
		if ((*s < '0' || *s > '9') && *s != '-' && *s != '+')
			return (0);
		++s;
		while (*s)
		{
			if (*s < '0' || *s > '9')
				return (0);
			++s;
		}
	}
	return (1);
}

int			find_lowest(t_stack *s, int size)
{
	int low;

	low = 0;
	if (s)
	{
		low = s->place;
		while (--size)
		{
			s = s->right;
			if (s->place < low)
				low = s->place;
		}
	}
	return (low);
}

int			find_highest(t_stack *s, int size)
{
	int high;

	high = 0;
	if (s)
	{
		high = s->place;
		while (--size)
		{
			s = s->right;
			if (s->place > high)
				high = s->place;
		}
	}
	return (high);
}
