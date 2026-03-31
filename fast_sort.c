/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 09:03:10 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/28 21:22:29 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*arr_index(t_stack **a)
{
	t_stack	*tmp;
	int		*arr;
	int		loc;

	arr = malloc(sizeof(int) * (count_size(*a)));
	if (!arr)
		return (0);
	tmp = *a;
	loc = 0;
	while (tmp)
	{
		arr[loc] = tmp->index;
		loc ++;
		tmp = tmp->next;
	}
	return (arr);
}

static int	check_if_sorted(int loc, int lenth, int loc2, int *arr)
{
	while (lenth > 0 && loc != loc2)
	{
		if (arr[loc] != (arr[loc + 1] - 1))
			return (1);
		loc++;
		lenth--;
	}
	return (0);
}

static int	part_one(t_stack **a, int *move, int *arr, int size)
{
	size = count_size(*a);
	arr = arr_index(a);
	if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
	{
		ra(a, move);
		sa(a, move);
		free(arr);
		return (0);
	}
	if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
	{
		ra(a, move);
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}

static int	part_two(t_stack **a, int *move, int *arr, int size)
{
	size = count_size(*a);
	arr = arr_index(a);
	if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
	{
		rra(a, move);
		free(arr);
		return (0);
	}
	if (arr[0] > arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
	{
		sa(a, move);
		free(arr);
		return (0);
	}
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
	{
		sa(a, move);
		ra(a, move);
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}

int	fast_sort(t_stack **a, int *move)
{
	int	*arr;
	int	size;

	size = count_size(*a);
	arr = arr_index(a);
	if ((size > 2) && (part_one(a, move, arr, size) == 0))
		return (0);
	if ((size > 2) && (part_two(a, move, arr, size) == 0))
		return (0);
	if ((size == 2) && (arr[0] > arr[1]))
	{
		sa(a, move);
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}
