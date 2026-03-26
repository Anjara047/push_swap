/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:00 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 16:38:05 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int *move)
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
	move[0]++;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b, int *move)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	move[1]++;
	write(1, "pa\n", 3);
}

void	ra(t_stack **a, int *move)
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
	move[2]++;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a, int *move)
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
	move[3]++;
	write(1, "rra\n", 4);
}
