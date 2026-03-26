/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:00 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 16:36:21 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int *move)
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
	move[4]++;
	write(1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b, int *move)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	move[5]++;
	write(1, "pb\n", 3);
}

void	rb(t_stack **b, int *move)
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
	move[6]++;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b, int *move)
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
	move[7]++;
	write(1, "rrb\n", 4);
}
