/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_benchmark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:19:48 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/26 20:13:48 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*choose_flag(int iflag)
{
	if (iflag == 1)
		return ("Simple");
	else if (iflag == 2)
		return ("Medium");
	else if (iflag == 3)
		return ("Complex");
	return ("Adaptive");
}

static char	*define_strat(int iflag, double disorder)
{
	if ((iflag == 1) || (((iflag == 4 || (!iflag)) && (disorder < 0.2))))
		return ("O(n2)");
	else if ((iflag == 2) || ((iflag == 4 || (!iflag)) && (disorder >= 0.2
				&& disorder < 0.5)))
		return ("O(n√n)");
	else if ((iflag == 3) || ((iflag == 4 || (!iflag)) && (disorder >= 0.5)))
		return ("O(n log n)");
	return ("Adaptive");
}

void	show_benchmark(double disorder, int iflag, int *move)
{
	char	*flag;
	char	*strat;
	int		total;

	flag = choose_flag(iflag);
	strat = define_strat(iflag, disorder);
	total = move[0] + move[1] + move[2] + move[3] + move[4] + move[5] + move[6]
		+ move[7] + move[8] + move[9] + move[10];
	ft_printf("[bench] disorder:	%f%%\n", (disorder * 100));
	ft_printf("[bench] strategy:	%s / %s\n", flag, strat);
	ft_printf("[bench] total_ops:	%d\n", total);
	ft_printf("[bench] sa:	%d	sb:	%d	ss:	%d	pa:	%d	pb:	%d\n", move[0],
		move[4], move[8], move[1], move[5]);
	ft_printf("[bench]	ra:	%d	rb:	%d	rr:	%d	rra:	%d	rrb:	%d",
		move[2], move[6], move[9], move[3], move[7]);
	ft_printf("	rrr:	%d\n", move[10]);
}
