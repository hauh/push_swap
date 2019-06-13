/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:30 by smorty            #+#    #+#             */
/*   Updated: 2019/06/12 22:10:11 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	if (*s && *s != (*s)->right)
	{
		g_coms = ft_strjoin(g_coms, (*s)->ab == 'a' ? "sa\n" : "sb\n");
		++g_count;
		(*s)->right->right->left = *s;
		(*s)->left->right = (*s)->right;
		(*s)->right->left = (*s)->left;
		(*s)->right = (*s)->right->right;
		(*s)->left->right->right = *s;
		(*s)->left = (*s)->left->right;
		(*s)->head = 0;
		*s = (*s)->left;
		(*s)->head = 1;
	}
}

void	push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a)
	{
		g_coms = ft_strjoin(g_coms, (*a)->ab == 'a' ? "pb\n" : "pa\n");
		(*a)->ab = ((*a)->ab == 'a' ? 'b' : 'a');
		++g_count;
		tmp = (*a == (*a)->right ? NULL : (*a)->right);
		(*a)->right->left = (*a)->left;
		(*a)->left->right = (*a)->right;
		(*a)->right->head = 1;
		if (*b)
		{
			(*a)->left = (*b)->left;
			(*b)->left->right = *a;
			(*b)->left = *a;
			(*a)->right = *b;
			(*b)->head = 0;
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

void	rotate(t_stack **s)
{
	if (*s && (*s)->right != *s)
	{
		g_coms = ft_strjoin(g_coms, (*s)->ab == 'a' ? "ra\n" : "rb\n");
		++g_count;
		(*s)->head = 0;
		(*s) = (*s)->right;
		(*s)->head = 1;
	}
}

void	reverse(t_stack **s)
{
	if (*s && (*s)->left != *s)
	{
		g_coms = ft_strjoin(g_coms, (*s)->ab == 'a' ? "rra\n" : "rrb\n");
		++g_count;
		(*s)->head = 0;
		(*s) = (*s)->left;
		(*s)->head = 1;
	}
}

/* linear
void	swap(t_stack **st)
{
	if (*st && (*st)->right)
	{
		(*st)->left = (*st)->right;
		(*st)->right = (*st)->right->right;
		(*st)->right->left = *st;
		(*st)->left->right = *st;
		(*st)->left->left = NULL;
		*st = (*st)->left;
		++g_count;
	}
}
void	push(t_stack **a, t_stack **b)
{
	if (*a)
	{
		if (*b)
			(*b)->left = *a;
		if ((*a)->right)
			(*a)->right->left = NULL;
		(*a)->left = (*a)->right;
		(*a)->right = *b;
		*b = *a;
		*a = (*b)->left;
		(*b)->left = NULL;
		++g_count;
	}
}
void	rotate(t_stack **st)
{
	t_stack *tmp;

	if (*st && (*st)->right)
	{
		tmp = *st;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = *st;
		tmp = *st;
		*st = (*st)->right;
		tmp->right = NULL;
		(*st)->left = tmp;
		++g_count;
	}
}
void	reverse(t_stack **st)
{
	t_stack *tmp;

	if (*st && (*st)->right)
	{
		tmp = *st;
		while (tmp->right->right)
			tmp = tmp->right;
		tmp->right->right = *st;
		*st = tmp->right;
		(*st)->left = NULL;
		tmp->right = NULL;
		++g_count;
	}
}*/
