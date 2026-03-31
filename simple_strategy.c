/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:38:16 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/28 13:54:03 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_strategy(t_stack **a, t_stack **b, int *move)
{
	int	size;

	if (!a || !(*a))
		return ;
	size = count_size(*a);
	if ((size <= 3) && (fast_sort(a, move) == 0))
		return ;
	while (*a)
	{
		move_min_top(a, move);
		pb(a, b, move);
	}
	while (*b)
		pa(a, b, move);
}
