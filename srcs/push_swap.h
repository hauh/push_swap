/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:40:26 by smorty            #+#    #+#             */
/*   Updated: 2019/06/13 22:51:33 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct	s_stack
{
	int				n;
	int				head;
	int				ab;
	int				place;
	struct s_stack	*right;
	struct s_stack	*left;
}				t_stack;

extern int g_count;
extern char *g_coms;

int				check_args(int argc, char **argv);
int				*get_array(int argc, char **argv);
void			sort_array(int *begin, int *end);
t_stack			*new_stack(int n);
t_stack			*store_stack(int argc, char **argv, int *size);
void			print_stack(t_stack *a, t_stack *b);
void			swap(t_stack **st);
void			push(t_stack **a, t_stack **b);
void			rotate(t_stack **st);
void			reverse(t_stack **st);
int				is_sorted(t_stack *s, int size);
void			split_a(t_stack **a, t_stack **b, int median, int size);
void			solve_3(t_stack **s);
void			solve_5(t_stack **a, t_stack **b, int size);
int				ft_printf(const char *format, ...);

#endif