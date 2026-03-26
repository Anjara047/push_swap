/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:47:16 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 19:12:32 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexup(unsigned int nbr)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr > 15)
		puthexup(nbr / 16);
	ft_putchar_fd(base[nbr % 16], 2);
}

static int	hexuplen(unsigned int nbr)
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

int	ft_puthexup(va_list args)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(args, unsigned int);
	puthexup(nbr);
	len = hexuplen(nbr);
	return (len);
}
