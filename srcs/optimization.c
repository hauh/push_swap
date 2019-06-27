/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:39:55 by smorty            #+#    #+#             */
/*   Updated: 2019/06/28 00:22:28 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_swap(int *ops)
{
	int *s;

	s = ops;
	if (*ops == SA)
	{
		while (*s != -1 && (*s == SA || *s == RA || *s == RRA || !*s))
			++s;
		if (*s == SB)
		{
			*ops = SS;
			*s = 0;
		}
	}
	else if (*s == SB)
	{
		while (*s != -1 && (*s == SB || *s == RB || *s == RRB || !*s))
			++s;
		if (*s == SA)
		{
			*ops = SS;
			*s = 0;
		}
	}
}

static void	optimize_rotate(int *ops)
{
	int *s;

	s = ops;
	if (*ops == RA)
	{
		while (*s != -1 && (*s == SA || *s == RA || *s == RRA || !*s))
			++s;
		if (*s == RB)
		{
			*ops = RR;
			*s = 0;
		}
	}
	else if (*s == RB)
	{
		while (*s != -1 && (*s == SB || *s == RB || *s == RRB || !*s))
			++s;
		if (*s == RA)
		{
			*ops = RR;
			*s = 0;
		}
	}
}

static void	optimize_reverse(int *ops)
{
	int *s;

	s = ops;
	if (*ops == RRA)
	{
		while (*s != -1 && (*s == SA || *s == RA || *s == RRA || !*s))
			++s;
		if (*s == RRB)
		{
			*ops = RRR;
			*s = 0;
		}
	}
	else if (*s == RRB)
	{
		while (*s != -1 && (*s == SB || *s == RB || *s == RRB || !*s))
			++s;
		if (*s == RRA)
		{
			*ops = RRR;
			*s = 0;
		}
	}
}

void		optimize_ops(int *ops)
{
	while (*ops != -1)
	{
		if (*ops == SA || *ops == SB)
			optimize_swap(ops);
		else if (*ops == RA || *ops == RB)
			optimize_rotate(ops);
		else if (*ops == RRA || *ops == RRB)
			optimize_reverse(ops);
		++ops;
	}
}
