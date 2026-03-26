/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:00 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/18 07:25:28 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_ab(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !(*a) || !((*a)->next))
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	pa_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	ra_ab(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !(*a) || !((*a)->next))
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = ft_stack_last(*a);
	last->next = first;
}

void	rra_ab(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev;

	if (!a || !(*a) || !((*a)->next))
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}
