/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:29:05 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/24 16:46:34 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_chunk_element(t_stack **a, int length, int end)
{
	t_stack	*tmp;
	int		loc;
	int		loc_top;
	int		loc_down;

	loc = 0;
	loc_top = 0;
	loc_down = 0;
	tmp = *a;
	while (tmp)
	{
		if ((tmp->index) < end)
			loc_down = loc;
		if (loc_down == 0)
			loc_top++;
		loc++;
		tmp = tmp->next;
	}
	if ((loc_top + 1) < (length - loc_down))
		return (1);
	return (0);
}

static void	push_chunk_to_b(t_stack **a, t_stack **b, int end, int *move)
{
	int	lim;
	int	length;
	int	next_chunk;

	length = count_size(*a);
	lim = ft_sqrt(length);
	next_chunk = next_chunk_element(a, length, end);
	while ((*a) && (lim > 0))
	{
		if ((*a)->index < end)
		{
			pb(a, b, move);
			if (((*b)->next) && ((*b)->index < ((*b)->next)->index))
				sb(b, move);
			if (((*b)->next) && ((*b)->index < (end / 2)))
				rb(b, move);
			next_chunk = next_chunk_element(a, length, end);
			lim--;
		}
		if (next_chunk == 1)
			ra(a, move);
		else
			rra(a, move);
	}
}

static int	push_max_to_a(t_stack **a, t_stack **b, int max, int *move)
{
	int	rb_nb;

	rb_nb = 0;
	while ((*b)->index != max)
	{
		if (((*b)->next)->index == max)
		{
			sb(b, move);
			break ;
		}
		rb(b, move);
		rb_nb++;
	}
	pa(a, b, move);
	while (rb_nb > 0)
	{
		rrb(b, move);
		rb_nb--;
		if ((*b)->index == (max - 1))
		{
			pa(a, b, move);
			max--;
		}
	}
	return (max);
}

void	medium_strategy(t_stack **a, t_stack **b, int *move)
{
	int	length;
	int	chunk_end;
	int	size;
	int	max_index;

	if (!((*a) || a))
		return ;
	length = count_size(*a);
	size = ft_sqrt(length);
	chunk_end = size;
	while (*a)
	{
		push_chunk_to_b(a, b, chunk_end, move);
		chunk_end = chunk_end + size;
	}
	max_index = length - 1;
	while (*b)
	{
		max_index = push_max_to_a(a, b, max_index, move);
		max_index--;
	}
}
