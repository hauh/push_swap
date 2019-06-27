/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:30 by smorty            #+#    #+#             */
/*   Updated: 2019/06/28 00:19:00 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_command(int operation, int **ops)
{
	int check;

	check = operation + *(*ops - 1);
	if (check == PA + PB || check == SA + SA || check == SB + SB
		|| check == RA + RRA || check == RB + RRB)
		*(--*ops) = 0;
	else
		*((*ops)++) = operation;
}

void		swap(t_stack **s, int **ops)
{
	if (*s && *s != (*s)->right)
	{
		if (ops)
			write_command((*s)->ab == 'a' ? SA : SB, ops);
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

void		push(t_stack **a, t_stack **b, int **ops)
{
	t_stack *tmp;

	if (*a)
	{
		if (ops)
			write_command((*a)->ab == 'a' ? PB : PA, ops);
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

void		rotate(t_stack **s, int **ops)
{
	if (*s && (*s)->right != *s)
	{
		if (ops)
			write_command((*s)->ab == 'a' ? RA : RB, ops);
		*s = (*s)->right;
	}
}

void		reverse(t_stack **s, int **ops)
{
	if (*s && (*s)->left != *s)
	{
		if (ops)
			write_command((*s)->ab == 'a' ? RRA : RRB, ops);
		*s = (*s)->left;
	}
}
