/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:33:29 by tsiarran          #+#    #+#             */
/*   Updated: 2026/02/18 15:28:10 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(int n)
{
	int	ln;

	ln = 0;
	if (n <= 0)
	{
		ln = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		ln++;
	}
	return (ln);
}

static void	reverse(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		loc;
	long	nb;

	loc = 0;
	nb = n;
	str = malloc(sizeof(char) * (len(n) + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[loc++] = '0';
	if (n < 0)
		nb = -nb;
	while (nb > 0)
	{
		str[loc++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[loc++] = '-';
	str[loc] = '\0';
	reverse(str, loc);
	return (str);
}
