/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 07:34:36 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/19 08:25:59 by tsanjara         ###   ########.fr       */
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

void	indexing(t_stack **a)
{
	int	*arr;
	int loc;
	int size;
	t_stack *tmp;

	if (!a || !(*a))
		return ;
	size = count_size(*a);
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
