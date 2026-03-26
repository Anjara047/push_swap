/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:19:19 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/25 11:46:22 by tsiarran         ###   ########.fr       */
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

void	complex_strategy(t_stack **a, t_stack **b, int *move)
{
	int	size;
	int	gap;
	int	max_gap;

	if (!a || !(*a))
		return ;
	gap = 0;
	max_gap = gap_max(a);
	while (gap < max_gap)
	{
		size = count_size(*a);
		while (size > 0)
		{
			if (get_bit((*a)->index, gap) == 0)
				pb(a, b, move);
			else
				ra(a, move);
			size--;
		}
		while (*b)
			pa(a, b, move);
		gap++;
	}
}
