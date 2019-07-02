/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:17:48 by smorty            #+#    #+#             */
/*   Updated: 2019/07/02 21:40:53 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker_operate(t_stack **a, t_stack **b, char *op)
{
	if (ft_strequ(op, "sa") || ft_strequ(op, "sb"))
		*(op + 1) == 'a' ? swap(a, NULL) : swap(b, NULL);
	else if (ft_strequ(op, "ss"))
	{
		swap(a, NULL);
		swap(b, NULL);
	}
	else if (ft_strequ(op, "ra") || ft_strequ(op, "rb"))
		*(op + 1) == 'a' ? rotate(a, NULL) : rotate(b, NULL);
	else if (ft_strequ(op, "rr"))
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
	else if (ft_strequ(op, "rra") || ft_strequ(op, "rrb"))
		*(op + 2) == 'a' ? reverse(a, NULL) : reverse(b, NULL);
	else if (ft_strequ(op, "rrr"))
	{
		reverse(a, NULL);
		reverse(b, NULL);
	}
	else if (ft_strequ(op, "pa") || ft_strequ(op, "pb"))
		*(op + 1) == 'a' ? push(b, a, NULL) : push(a, b, NULL);
	else
		error();
}

static int	checker(t_stack **a, int fd, int flag, int size)
{
	t_stack	*b;
	char	*op;
	int		gnl;

	b = NULL;
	if (flag)
	{
		ft_printf("\e[H\e[J");
		print_stacks(*a, b, "   ", flag);
	}
	while ((gnl = get_next_line(fd, &op)) > 0)
	{
		checker_operate(a, &b, op);
		free(op);
		if (flag)
			print_stacks(*a, b, op, flag);
	}
	if (gnl < 0)
		error();
	if (is_sorted(*a, size))
		return (1);
	while (b)
		push(&b, a, NULL);
	return (0);
}

static int	get_flag(char *arg)
{
	int flag;

	flag = 0;
	while (*arg)
	{
		if (*arg == 'n' && flag % 100 == 0)
		{
			flag += 10;
			if (*(arg + 1) > '0' && *(arg + 1) <= '9')
				flag += *++arg - '0';
		}
		else if (*arg == 'v' && flag % 100 == 0)
		{
			flag += 20;
			if (*(arg + 1) > '0' && *(arg + 1) <= '9')
				flag += *++arg - '0';
		}
		else if (*arg == 'f' && flag < 100)
			flag += 100;
		else
			error();
		++arg;
	}
	return (flag);
}

static int	check_flag(char ***argv, int *flag, int *fd)
{
	++*argv;
	*fd = 0;
	*flag = 0;
	if (***argv != '-' || (*(**argv + 1) > '0' && *(**argv + 1) <= '9'))
		return (0);
	*flag = get_flag(++*(*argv)++);
	if (*flag >= 100)
	{
		if ((*fd = open(*(*argv)++, O_RDONLY)) < 0)
			error();
		*flag -= 100;
		return (2);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	int		*arr;
	int		size;
	int		flag;
	int		fd;

	if (argc-- < 2 || (argc -= check_flag(&argv, &flag, &fd)) < 1)
		return (0);
	if (!(arr = get_array(argc, argv, &size)))
		error();
	a = store_stack(arr, size);
	sort_array(arr, arr + size - 1);
	mark_stack(a, arr, size);
	ft_printf(checker(&a, fd, flag, size) ? "OK\n" : "KO\n");
	if (fd)
		close(fd);
	free_stack(a, size);
	free(arr);
	return (0);
}
