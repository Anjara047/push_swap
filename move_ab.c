/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:04:58 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/15 20:48:53 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sa_ab(a);
	sb_ab(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra_ab(a);
	rb_ab(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra_ab(a);
	rrb_ab(b);
	write(1, "rrr\n", 4);
}
