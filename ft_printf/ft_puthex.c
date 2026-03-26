/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:47:16 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 19:12:17 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthex(unsigned int nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		puthex(nbr / 16);
	}
	ft_putchar_fd(base[nbr % 16], 2);
}

static int	hexlen(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr > 15)
	{
		nbr = nbr / 16;
		len ++;
	}
	return (len);
}

int	ft_puthex(va_list args)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	nbr = va_arg(args, unsigned int);
	puthex(nbr);
	len = hexlen(nbr);
	return (len);
}
