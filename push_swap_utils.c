/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 00:49:45 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/28 21:22:23 by tsanjara         ###   ########.fr       */
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
		choose_strat(a, b, flag, move);
	else
		adaptive_strategy(a, b, flag, move);
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
	}
}
