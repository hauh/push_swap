/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:40:26 by smorty            #+#    #+#             */
/*   Updated: 2019/06/30 23:39:56 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include "../srcs/ft_printf/includes/ft_printf.h"
# include "../srcs/get_next_line/get_next_line.h"

# define SA 1
# define RA 10
# define RRA 100
# define PA 1000
# define SB 3
# define RB 30
# define RRB 300
# define PB 3000
# define SS 5
# define RR 50
# define RRR 500

typedef struct	s_stack
{
	int				n;
	int				ab;
	int				place;
	struct s_stack	*right;
	struct s_stack	*left;
}				t_stack;

int				*get_array(int argc, char **argv, int *size);
void			sort_array(int *begin, int *end);
t_stack			*store_stack(int *arr, int size);
void			mark_stack(t_stack *a, int *arr, int size);
void			sort_3(t_stack **s, int **ops);
void			sort_5(t_stack **a, t_stack **b, int size, int **ops);
void			sort_100(t_stack **a, t_stack **b, int size, int **ops);
void			sort_500(t_stack **a, t_stack **b, int high, int **ops);
void			print_stacks(t_stack *a, t_stack *b, char *com, int flag);
void			swap(t_stack **s, int **ops);
void			push(t_stack **a, t_stack **b, int **ops);
void			rotate(t_stack **s, int **ops);
void			reverse(t_stack **s, int **ops);
int				is_sorted(t_stack *s, int size);
int				find_lowest(t_stack *a, int size);
int				find_highest(t_stack *a, int size);
int				stack_size(t_stack *a);
void			optimize_ops(int *ops);
void			free_stack(t_stack *s, int size);
void			error(void);

void	sort_3_ascending(t_stack **s, int **ops);

#endif
