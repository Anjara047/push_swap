/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 00:49:45 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/27 01:26:59 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice(t_stack **a, t_stack **b, int *flag, int *move)
{
	double	disorder;

	disorder = count_disorder(a);
	if (disorder == 0)
		return ;
	if (flag[1] && flag[2])
		choose_strat(a, b, flag[2], move);
	else
		adaptive_strategy(a, b, disorder, move);
}

void	check_param(int argc, char **argv, int *flag)
{
	if (argc <= 2)
	{
		if (argc == 1)
		{
			free(flag);
			exit(1);
		}
		if (check_arg(argv, 1) == 1 && !((argv[1][0]) >= 48
			&& (argv[1][0] <= 57)))
		{
			free(flag);
			error_mess();
		}
	}
}
