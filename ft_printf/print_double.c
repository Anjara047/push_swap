/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:35:54 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/26 19:51:44 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putint(int nbr)
{
	int		len;
	char	*tmp;

	ft_putnbr_fd(nbr, 2);
	tmp = ft_itoa(nbr);
	len = (int)ft_strlen(tmp);
	free(tmp);
	return (len);
}

int	print_double(va_list args)
{
	int		int_part;
	int		int_nb;
	int		dec_part;
	int		len;
	double	nb;

	nb = va_arg(args, double);
	len = 0;
	int_part = (int)nb;
	int_nb = int_part;
	len = len + putint(int_part);
	write(2, ".", 1);
	len++;
	dec_part = (int)((nb - (int_nb)) * 100);
	if (dec_part != 0)
		len = len + putint(dec_part);
	else if (dec_part == 0)
	{
		len = len + 2;
		write(2, "00", 2);
	}
	return (len);
}
