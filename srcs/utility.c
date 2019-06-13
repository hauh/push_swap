/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:43:58 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 22:46:19 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	char *s;

	if (argc < 1)
		return (0);
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

int		is_sorted(t_stack *s, int size)
{
	t_stack *r;

	r = s;
	r = r->right;
	--size;
	while (r != s)
	{
		if (r->n < r->left->n)
			return (0);
		r = r->right;
		--size;
	}
	if (size != 0)
		return (0);
	return (1);
}
