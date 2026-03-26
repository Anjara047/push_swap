/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:02:11 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/26 21:24:38 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(long res, int sign)
{
	if (((sign == 1) && (res > INT_MAX)) || ((sign == -1)
			&& (res > ((long)INT_MAX + 1))))
		return (1);
	return (0);
}

static int	check_nb(char *nb, int loc)
{
	if (!(nb[loc] >= '0' && nb[loc] <= '9'))
		return (1);
	return (0);
}

static int	check_after_nb(char *nb, int loc)
{
	if (nb[loc] != '\0')
		return (1);
	return (0);
}

static void	manage_space(char *nb, int loc)
{
	while ((nb[loc] >= 9 && nb[loc] <= 13) || (nb[loc] == 32))
		loc++;
}

int	ft_atoi(char *nb, int *error)
{
	int		loc;
	long	res;
	int		sign;

	loc = 0;
	res = 0;
	sign = 1;
	manage_space(nb, loc);
	if (nb[loc] == '-' || nb[loc] == '+')
	{
		if (nb[loc] == '-')
			sign = -1;
		loc++;
	}
	error[0] = check_nb(nb, loc);
	while (nb[loc] >= '0' && nb[loc] <= '9')
	{
		res = (res * 10) + (nb[loc] - 48);
		if (check_overflow(res, sign))
			error[0] = 1;
		loc++;
	}
	if (check_after_nb(nb, loc))
		error[0] = 1;
	return ((int)(res * sign));
}
