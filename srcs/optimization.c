/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:39:55 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 23:50:47 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	opttimize_swap(char *coms)
{
	char	*s;
	int		sa;
	int		sb;

	sa = 0;
	sb = 0;
	s = coms;
	while (*s != 'b' && *s != 'p')
	{
		if (*s == 's')
		++sa;
		++s;
	}
	while (*s != 'a' && *s != 'p')
	{
		if (*s == 's')
		++sb;
		++s;
	}
}

static	void	optimize_rotate(char *coms)
{
	char	*s;
	int		ra;
	int		rb;
}

void		optimize_coms(char *coms)
{
	optimize_swap(coms);
	optimize_rotate(coms);
	optimize_reverse(coms);
}