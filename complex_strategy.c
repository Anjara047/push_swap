/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:19:19 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/23 20:08:48 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	gap_max(t_stack **a)
{
	int	index_max;
	int	max_gap;
	int	q;

	max_gap = 0;
	index_max = count_size(*a) - 1;
	q = index_max;
	while (q != 1)
	{
		q = q / 2;
		max_gap++;
	}
	return (max_gap + 1);
}

void	complex_strategy(t_stack **a, t_stack **b)
{
	int	size;
	int	gap;
	int	max_gap;

	gap = 0;
	max_gap = gap_max(a);
	while (gap < max_gap)
	{
		size = count_size(*a);
		while (size > 0)
		{
			if (((((*a)->index) >> gap) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			size--;
		}
		while (*b)
			pa(a, b);
		gap++;
	}
}
