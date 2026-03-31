/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:15:02 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/28 20:16:25 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stack **a, t_stack **b, int *flag, int *move)
{
	int		size;
	double	disorder;

	disorder = count_size(*a);
	size = count_size(*a);
	if (!a || !(*a) || disorder == 0)
		return ;
	if ((size <= 5) || disorder < 0.2000)
	{
		flag[2] = 1;
		simple_strategy(a, b, move);
		return ;
	}
	else if (disorder >= 0.2000 && disorder < 0.5000)
	{
		medium_strategy(a, b, move);
		return ;
	}
	else if (disorder >= 0.5000)
	{
		complex_strategy(a, b, move);
		return ;
	}
}
