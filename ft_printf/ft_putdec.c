/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:34:33 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 19:12:08 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(va_list args)
{
	int		nbr;
	char	*tmp;
	int		len;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 2);
	tmp = ft_itoa(nbr);
	len = (int)ft_strlen(tmp);
	free(tmp);
	return (len);
}
