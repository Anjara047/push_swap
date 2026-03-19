/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 07:31:59 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/19 08:25:34 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stack_last(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (NULL);
	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_stackclear(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

void	ft_add_stack_back(t_stack *new, t_stack **a)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!(*a))
	{
		*a = new;
		return ;
	}
	last = ft_stack_last(*a);
	last->next = new;
}

int	count_size(t_stack *a)
{
	t_stack *tmp;
	int size;

	if (!a)
		return (0);
	size = 0;
	tmp = a;
	while(tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
