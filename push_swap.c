/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 07:33:05 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/19 08:28:28 by tsanjara         ###   ########.fr       */
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
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static void	parse(char	**argv, t_stack **a)
{
	int		loc;
	int		value;
	t_stack *new;

	loc = 1;
	while (argv[loc])
	{
		value = ft_atoi(argv[loc]);
		new = ft_stack_new(value);
		if (!new)
		{
			ft_stackclear(a);
			return ;
		}
		ft_add_stack_back(new, a);
		loc++;
	}
}

static void	push_swap(char	**argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	parse(argv, &a);
	check_duplicates(&a);
	indexing(&a);
//	simple_strategy(&a, &b);
	medium_strategy(&a, &b);
	ft_stackclear(&a);
	ft_stackclear(&b);
}

int	main(int argc, char	**argv)
{
	if	(argc < 2)
		return (0);
	push_swap(argv);
}
