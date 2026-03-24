/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:02:11 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/23 19:39:33 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_overflow(long res, int sign)
{
	if (((sign == 1) && (res > INT_MAX))
		|| ((sign == -1) && (res > ((long)INT_MAX + 1))))
		error_mess();
}

static void	check_nb(char *nb, int loc)
{
	if (!(nb[loc] >= '0' && nb[loc] <= '9'))
		error_mess();
}

static void	check_after_nb(char *nb, int loc)
{
	if (nb[loc] != '\0')
		error_mess();
}

int	ft_atoi(char *nb)
{
	int		loc;
	long	res;
	int		sign;

	loc = 0;
	res = 0;
	sign = 1;
	while ((nb[loc] >= 9 && nb[loc] <= 13) || (nb[loc] == 32))
		loc++;
	if (nb[loc] == '-' || nb[loc] == '+')
	{
		if (nb[loc] == '-')
			sign = -1;
		loc++;
	}
	check_nb (nb, loc);
	while (nb[loc] >= '0' && nb[loc] <= '9')
	{
		res = (res * 10) + (nb[loc] - 48);
		check_overflow(res, sign);
		loc++;
	}
	check_after_nb(nb, loc);
	return ((int)(res * sign));
}
