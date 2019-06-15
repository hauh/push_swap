/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:39:55 by smorty            #+#    #+#             */
/*   Updated: 2019/06/15 22:34:58 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_swap(int *coms)
{
	int *s;

	s = coms;
	if (*coms == SA)
	{
		while ((*s == SA || *s == RA || *s == RRA || *s == SS || !*s) && *s != -1)
			++s;
		if (*s == SB)
		{
			*coms = SS;
			*s = 0;
		}
	}
	else if (*s == SB)
	{
		while ((*s == SB || *s == RB || *s == RRB || *s == SS || !*s) && *s != -1)
			++s;
		if (*s == SA)
		{
			*coms = SS;
			*s = 0;
		}
	}
}

static void	optimize_rotate(int *coms)
{
	int *s;

	s = coms;
	if (*coms == RA)
	{
		while ((*s == SA || *s == RA || *s == RRA || *s == RR || !*s) && *s != -1)
			++s;
		if (*s == RB)
		{
			*coms = RR;
			*s = 0;
		}
	}
	else if (*s == RB)
	{
		while ((*s == SB || *s == RB || *s == RRB || *s == RR || !*s) && *s != -1)
			++s;
		if (*s == RA)
		{
			*coms = RR;
			*s = 0;
		}
	}
}

static void	optimize_reverse(int *coms)
{
	int *s;

	s = coms;
	if (*coms == RRA)
	{
		while ((*s == SA || *s == RA || *s == RRA || *s == RRR || !*s) && *s != -1)
			++s;
		if (*s == RRB)
		{
			*coms = RRR;
			*s = 0;
		}
	}
	else if (*s == RRB)
	{
		while ((*s == SB || *s == RB || *s == RRB || *s == RRR || !*s) && *s != -1)
			++s;
		if (*s == RRA)
		{
			*coms = RRR;
			*s = 0;
		}
	}
}

void		optimize_coms(int *coms)
{
	while (*coms != -1)
	{
		if (*coms == SA || *coms == SB)
			optimize_swap(coms);
		else if (*coms == RA || *coms == RB)
			optimize_rotate(coms);
		else if (*coms == RRA || *coms == RRB)
			optimize_reverse(coms);
		++coms;
	}
}
