/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:03:33 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/21 08:42:11 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *arr, int size)
{
	int	tmp;
	int	loc;
	int	loc2;

	loc = 0;
	while (loc < size)
	{
		loc2 = loc + 1;
		while (loc2 < size)
		{
			if (arr[loc] > arr[loc2])
			{
				tmp = arr[loc];
				arr[loc] = arr[loc2];
				arr[loc2] = tmp;
			}
			loc2++;
		}
		loc++;
	}
}

static int	pick_index(int *arr, int value, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}



void	indexing(t_stack **a, int size)
{
	int	*arr;
	int loc;
	t_stack *tmp;

	if (!a || !(*a))
		return ;
	loc = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	tmp = *a;
	while (tmp)
	{
		arr[loc++] = tmp->value;
		tmp = tmp->next;
	}
	sort_arr(arr, size);
	tmp = *a;
	while (tmp)
	{
		tmp->index = pick_index(arr, tmp->value, size);
		tmp = tmp->next;
	}
	free (arr);
}
