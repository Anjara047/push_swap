/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_min_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:48:26 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/24 08:35:12 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//when the number is just 3 here, here is to function to call
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
		// 2 1 3
	if (top > mid && mid < bot && top < bot)
		sa(a);
		// 3 2 1
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
		// 3 1 2
	else if (top > mid && mid < bot && top > bot)
		ra(a);
		// 1 3 2
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
		// 2 3 1
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}
