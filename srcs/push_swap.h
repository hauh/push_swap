/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:40:26 by smorty            #+#    #+#             */
/*   Updated: 2019/06/22 22:51:21 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define SA 11
# define RA 12
# define RRA 13
# define SB 21
# define RB 22
# define RRB 23
# define SS 31
# define RR 33
# define RRR 34
# define PA 41
# define PB 42

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

int				check_args(int argc, char **argv);
t_stack			*new_stack(int n);
t_stack			*store_stack(int argc, char **argv, int *size);
int				*get_array(int argc, char **argv);
void			sort_array(int *begin, int *end);
void			mark_stack(t_stack *a, int *arr, int size);
void			print_stack(t_stack *a, t_stack *b);
void			swap(t_stack **st, int **coms);
void			push(t_stack **a, t_stack **b, int **coms);
void			rotate(t_stack **st, int **coms);
void			reverse(t_stack **st, int **coms);
int				is_sorted(t_stack *s, int size);
int				find_lowest(t_stack *a, int size);
int				find_highest(t_stack *a, int size);
int				stack_size(t_stack *a);
void			sort_100(t_stack **a, t_stack **b, int size, int **coms);
void			split_a(t_stack **a, t_stack **b, int size, int **coms);
void			solve_3(t_stack **s, int **coms);
void			solve_5_a(t_stack **a, t_stack **b, int size, int **coms);
void			solve_5_b(t_stack **a, t_stack **b, int size, int **coms);
void			optimize_coms(int *coms);
int				ft_printf(const char *format, ...);
void			quicksort_ascending(t_stack **a, t_stack **b, int high, int **coms);

#endif
