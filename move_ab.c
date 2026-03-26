/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:04:58 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 16:38:47 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, int *move)
{
	sa_ab(a);
	sb_ab(b);
	move[8]++;
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b, int *move)
{
	ra_ab(a);
	rb_ab(b);
	move[9]++;
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b, int *move)
{
	rra_ab(a);
	rrb_ab(b);
	move[10]++;
	write(1, "rrr\n", 4);
}
