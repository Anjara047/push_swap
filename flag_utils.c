/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 07:21:36 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/21 10:09:30 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_flag(char *flag, int loc, char *strategy, int result)
{
	int	loc2;

	if (!strategy)
		return (0);
	loc2 = 0;
	while (flag[loc])
	{
		if (flag[loc] != strategy[loc2])
			return (0);
		loc2++;
		loc++;
	}
	return (result);
}


int	check_flag(char *flag)
{
	int	loc;

	loc = 0;
	while(flag[loc] == '-' && loc < 2)
	{
		loc++;
	}
	if (flag[loc] != '-' && loc < 2)
		return (0);
	if (valid_flag(flag, loc, "simple", 1) == 1)
		return (1);
	else if (valid_flag(flag, loc, "medium", 2) == 2)
		return (2);
	else if (valid_flag(flag, loc, "complex", 3) == 3)
		return (3);
	else if (valid_flag(flag, loc, "adaptive", 4) == 4)
		return (4);
	return (0);
}

void	choose_strat(t_stack **a, t_stack **b, int flag)
{
	double	disorder;

	if (!(*a) || !a)
		return ;
	if (flag == 1)
		simple_strategy(a, b);
	else if (flag == 2)
		medium_strategy(a, b);
	else if (flag == 3)
		complex_strategy(a, b);
	else if (flag == 4)
	{
		disorder = count_disorder(a);
		adaptive_strategy(a, b, disorder);
	}
}
