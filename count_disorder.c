/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:42:10 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/24 01:35:44 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	count_disorder(t_stack **a)
{
	t_stack	*current;
	t_stack	*runner;
	int		mistakes;
	int		total_pairs;

	if (!a || !(*a) || !(*a)->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = *a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs++;
			if (current->index > runner->index)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	return (((double)mistakes / (double)total_pairs) * 100);
}
