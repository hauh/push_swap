/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:30 by smorty            #+#    #+#             */
/*   Updated: 2019/06/23 19:56:25 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s, int **coms)
{
	if (*s && *s != (*s)->right)
	{
		if (coms)
		{
			if (((*s)->ab == 'a' && *(*coms - 1) == SA) ||
				((*s)->ab == 'b' && *(*coms - 1) == SB))
				*(--*coms) = 0;
			else
				*((*coms)++) = ((*s)->ab == 'a' ? SA : SB);
		}
		if ((*s)->right->right != *s)
		{
			(*s)->right->right->left = *s;
			(*s)->left->right = (*s)->right;
			(*s)->right->left = (*s)->left;
			(*s)->right = (*s)->right->right;
			(*s)->left->right->right = *s;
			(*s)->left = (*s)->left->right;
		}
		*s = (*s)->left;
	}
}

void	push(t_stack **a, t_stack **b, int **coms)
{
	t_stack *tmp;

	if (*a)
	{
		if (coms)
		{
			if (((*a)->ab == 'a' && *(*coms - 1) == PA) ||
				((*a)->ab == 'b' && *(*coms - 1) == PB))
				*(--*coms) = 0;
			else
				*((*coms)++) = ((*a)->ab == 'a' ? PB : PA);
		}
		(*a)->ab = ((*a)->ab == 'a' ? 'b' : 'a');
		tmp = (*a == (*a)->right ? NULL : (*a)->right);
		(*a)->right->left = (*a)->left;
		(*a)->left->right = (*a)->right;
		if (*b)
		{
			(*a)->left = (*b)->left;
			(*b)->left->right = *a;
			(*b)->left = *a;
			(*a)->right = *b;
		}
		else
		{
			(*a)->left = *a;
			(*a)->right = *a;
		}
		*b = *a;
		*a = tmp;
	}
}

void	rotate(t_stack **s, int **coms)
{
	if (*s && (*s)->right != *s)
	{
		if (coms)
		{
			if (((*s)->ab == 'a' && *(*coms - 1) == RRA) ||
				((*s)->ab == 'b' && *(*coms - 1) == RRB))
				*(--*coms) = 0;
			else
				*((*coms)++) = ((*s)->ab == 'a' ? RA : RB);
		}
		*s = (*s)->right;
	}
}

void	reverse(t_stack **s, int **coms)
{
	if (*s && (*s)->left != *s)
	{
		if (coms)
		{
			if (((*s)->ab == 'a' && *(*coms - 1) == RA) ||
				((*s)->ab == 'b' && *(*coms - 1) == RB))
				*(--*coms) = 0;
			else
				*((*coms)++) = ((*s)->ab == 'a' ? RRA : RRB);
		}
		*s = (*s)->left;
	}
}
