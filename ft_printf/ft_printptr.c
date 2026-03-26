/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:42:11 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 19:11:40 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthex(unsigned long nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
		puthex(nbr / 16);
	ft_putchar_fd(base[nbr % 16], 2);
}

static int	nblen(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr >= 1)
	{
		nbr = nbr / 16;
		len ++;
	}
	return (len);
}

int	ft_printptr(va_list args)
{
	void				*ptr;
	unsigned long		nbr;
	int					len;

	ptr = va_arg(args, void *);
	nbr = (unsigned long)ptr;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 2);
		return (5);
	}
	ft_putstr_fd("0x", 2);
	puthex(nbr);
	len = 2 + nblen(nbr);
	return (len);
}
