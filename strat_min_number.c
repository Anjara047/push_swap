/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_min_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:48:26 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/24 07:58:13 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strat_min_number(t_stack **a)
{
	int	min_pos;
	int	top;
	int	mid;
	int	bot;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	min_pos = find_min_position(a);
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}
