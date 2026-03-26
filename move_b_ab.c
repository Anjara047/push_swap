/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:55:58 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/26 19:37:19 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_ab(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !(*b) || !((*b)->next))
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	pb_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	rb_ab(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !(*b) || !((*b)->next))
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = ft_stack_last(*b);
	last->next = first;
}

void	rrb_ab(t_stack **b)
{
	t_stack	*last;
	t_stack	*prev;

	if (!b || !(*b) || !((*b)->next))
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
}
