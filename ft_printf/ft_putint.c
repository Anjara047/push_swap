/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:46:37 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 19:12:40 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(va_list args)
{
	int		nbr;
	int		len;
	char	*tmp;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 2);
	tmp = ft_itoa(nbr);
	len = (int)ft_strlen(tmp);
	free(tmp);
	return (len);
}
