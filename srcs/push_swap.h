/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:40:26 by smorty            #+#    #+#             */
/*   Updated: 2019/06/07 20:53:33 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_stack
{
	int				n;
	struct s_stack	*next;
}				t_stack;

t_stack			*new_stack(int n);
t_stack			*store_stack(int argc, char **argv);
void			swap(t_stack **st);
void			push(t_stack **a, t_stack **b);
void			rotate(t_stack **st);
void			reverse(t_stack **st);

#endif