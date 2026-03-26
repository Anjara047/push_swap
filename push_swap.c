/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:02:01 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/27 01:26:51 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
			{
				ft_stackclear(a);
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	parse(char **argv, t_stack **a, int *flag, int loc)
{
	int		error[1];

	error[0] = 0;
	if (loc == 1)
		error[0] = f_affect(a, argv, flag, error);
	else if (loc == 0)
		error[0] = s_affect(a, argv, flag, error);
	if (error[0] == 1)
	{
		ft_stackclear(a);
		return (1);
	}
	return (0);
}

static double	push_swap(char **argv, int *move, int *flag)
{
	t_stack	*a;
	t_stack	*b;
	double	disorder;
	int		size;

	a = NULL;
	b = NULL;
	if (parse(argv, &a, flag, 1) != 1)
	{
		size = count_size(a);
		if (check_duplicates(&a) == 1)
		{
			ft_stackclear(&a);
			return (2.0);
		}
		indexing(&a, size);
		disorder = count_disorder(&a);
		choice(&a, &b, flag, move);
		ft_stackclear(&a);
		ft_stackclear(&b);
		if (size == 0)
			return (2.0);
		return (disorder);
	}
	return (2.0);
}

int	check_arg(char **argv, int loc)
{
	int	loc2;
	int	space;

	loc2 = 0;
	space = 0;
	while (argv[loc][loc2] != '\0')
	{
		if (argv[loc][loc2] == 32)
			space++;
		loc2++;
	}
	if (space == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		move[11];
	int		loc;
	double	disorder;
	int		*flag;

	flag = verify_flag(argv);
	loc = 0;
	while (loc < 11)
		move[loc++] = 0;
	check_param(argc, argv, flag);
	disorder = push_swap(argv, move, flag);
	if (disorder == 0.0)
	{
		free(flag);
		exit(1);
	}
	else if (disorder == 2.0)
	{
		free(flag);
		error_mess();
	}
	if (flag[0] != 0)
		show_benchmark(disorder, flag[2], move);
	free(flag);
}
