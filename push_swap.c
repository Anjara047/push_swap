/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:02:01 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/20 23:28:07 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(t_stack **a)
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
				error_mess();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static void	parse(char	**argv, t_stack **a, int loc)
{
	int		value;
	t_stack *new;

	while (argv[loc])
	{
		if (check_arg(argv, loc) == 0)
			parse(ft_split(argv[loc], 32), a, 0);
		else
		{
			value = ft_atoi(argv[loc]);
			new = ft_stack_new(value);
			if (!new)
			{
				ft_stackclear(a);
				return ;
			}
			ft_add_stack_back(new, a);
		}
		loc++;
	}
}

static void	push_swap(char	**argv)
{
	t_stack	*a;
	t_stack	*b;
	int		flag;
	int		disorder;
	int		size;

	a = NULL;
	b = NULL;
	size = count_size(a);
	flag = check_flag(argv[1]);//(to be created)
	if (flag == 1)
		parse(argv, &a, 2);
	else
		parse(argv, &a, 1);
	check_duplicates(&a);
	indexing(&a, size);
	if (flag == 1)
		choose_strat(&a, &b);//(to be created similar to the fucking adaptive)
	else
	{
		disorder = count_disorder(&a);
		adaptive_strategy(&a, &b, disorder);
	}
	ft_stackclear(&a);
	ft_stackclear(&b);
}

int check_arg(char **argv, int loc)
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

int	main(int argc, char	**argv)
{
	if (argc <= 2)
	{
		if ((argc == 1) || (check_arg(argv, 1) == 1))
			error_mess();
	}
	push_swap(argv);
}
