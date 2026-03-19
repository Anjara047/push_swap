/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:38:16 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/19 07:32:38 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_strategy(t_stack **a, t_stack **b)
{
	int size;

	if (!a || !(*a))
		return ;
	size = count_size(*a);
	while (*a)
	{
		move_min_top(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
