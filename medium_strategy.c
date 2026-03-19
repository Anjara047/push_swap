/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:29:05 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/19 11:52:38 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_chunk_element(t_stack **a, int chunk_start, int chunk_end, int chunk_size)
{
	t_stack	*tmp;
	int		bottom;
	int		top;
	int		loc;

	tmp = (*a);
	while (tmp)
	{
		if ((loc < (chunk_size / 2)) && (tmp->index >= chunk_start && tmp->index < chunk_end))
			top++;
		if ((loc >= (chunk_size / 2)) && (tmp->index >= chunk_start && tmp->index < chunk_end))
			bottom++;
		tmp = tmp->next;
		loc++;
	}
	if (top > bottom)
		return (0);
	return (1);
}

static void push_to_b(t_stack **a, t_stack **b, int chunk_start, int chunk_end)
{
	int	lim;
	int	smth;
	int	chunk_size;

	chunk_size =  count_size(*a);
	chunk_end = ft_sqrt(chunk_size);
	lim = chunk_end;
	smth = count_chunk_element(a, chunk_start, chunk_end, chunk_size);
	while ((*a) && (lim > 0))
	{
		if ((*a)->index >= chunk_start && (*a)->index < chunk_end)
		{
			pb(a, b);
			lim--;
		}
		if(smth == 0)
			ra(a);
		else
			rra (a);
	}
}

void	medium_strategy(t_stack **a, t_stack **b)
{
	int	chunk_start;
	int	chunk_size;
	int	chunk_end;

	chunk_start = 0;
	chunk_size = count_size(*a);
	chunk_end = ft_sqrt(chunk_size);
	while (*a)
	{
		push_to_b(a, b, chunk_start, chunk_end);
		chunk_start = chunk_end;
		chunk_end = chunk_size + chunk_size;
	}
	while (*b)
	{
		pa(a, b);
	}
}
