/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 07:34:10 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/19 07:34:19 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_overflow(long res, int sign)
{
	if (((sign == 1) && (res > INT_MAX)) 
		|| ((sign == -1) && (res > ((long)INT_MAX + 1))))
	{
		write (2, "Error\n", 6);
		exit(1);
	}
}

static void	check_nb(char *nb, int loc)
{
	if (!(nb[loc] >= '0' && nb[loc] <= '9'))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	check_after_nb(char *nb, int loc)
{
	if (nb[loc] != '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	ft_atoi(char *nb)
{
	int	loc;
	long	res;
	int	sign;

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
	check_nb(nb,loc);
	while (nb[loc] >= '0' && nb[loc] <= '9')
	{
		res = (res * 10) + (nb[loc] - 48);
		check_overflow(res, sign);
		loc++;
	}
	check_after_nb(nb, loc);
	return ((int)(res * sign));
}
