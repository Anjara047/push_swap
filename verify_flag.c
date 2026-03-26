/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:51:11 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/26 20:29:22 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*surf(char **argv, int *result, int flag_nb, int bench_nb)
{
	int	loc;
	int	flag;

	loc = 1;
	while (argv[loc])
	{
		flag = check_flag(argv[loc]);
		if (flag)
		{
			if ((flag) == 5)
			{
				result[0] = loc;
				bench_nb++;
			}
			else
			{
				result[1] = loc;
				result[2] = flag;
				flag_nb++;
			}
		}
		loc++;
	}
	return (result);
}

int	*verify_flag(char **argv)
{
	int	*result;
	int	flag_nb;
	int	bench_nb;
	int	loc;

	result = malloc(sizeof(int) * 3);
	if (!result)
		error_mess();
	bench_nb = 0;
	flag_nb = 0;
	while (loc < 3)
		result[loc++] = 0;
	result = surf(argv, result, flag_nb, bench_nb);
	if (bench_nb > 1 || flag_nb > 1)
	{
		free(result);
		error_mess();
	}
	return (result);
}
