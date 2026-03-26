/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:32:30 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 19:13:11 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putunbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static int	udeclen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

int	ft_putudec(va_list args)
{
	unsigned int		nbr;
	int					len;

	nbr = va_arg(args, unsigned int);
	ft_putunbr_fd(nbr, 2);
	len = udeclen(nbr);
	return (len);
}
