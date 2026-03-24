/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:15:02 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 06:41:04 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stack **a, t_stack **b, double disorder)
{
	if (!a || !(*a) || disorder == 0)
		return ;
	if (disorder < 0.2)
	{
		simple_strategy(a, b);
		return ;
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		medium_strategy(a, b);
		return ;
	}
	else if (disorder >= 0.5)
	{
		complex_strategy(a, b);
		return ;
	}
}
