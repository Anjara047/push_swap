/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:41:30 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/26 19:36:03 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int nb, int bit)
{
	int	loc;

	loc = 0;
	while (loc < bit)
	{
		nb = nb / 2;
		loc++;
	}
	return (nb % 2);
}
