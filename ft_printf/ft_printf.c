/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:34:33 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/25 07:08:52 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(args));
	if (c == 's')
		return (ft_putstr(args));
	if (c == 'p')
		return (ft_printptr(args));
	if (c == 'd')
		return (ft_putdec(args));
	if (c == 'i')
		return (ft_putint(args));
	if (c == 'u')
		return (ft_putudec(args));
	if (c == 'x')
		return (ft_puthex(args));
	if (c == 'X')
		return (ft_puthexup(args));
	if (c == '%')
		return (ft_putpercent());
	if (c == 'f')
		return (print_double(args));
	return (0);
}

static int	check(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%' || c == 'f')
		return (1);
	if (c == ' ')
		return (2);
	return (0);
}

static int	display(va_list args, const char *s, int len, int loc)
{
	int	lim;

	lim = 0;
	while (s[loc])
	{
		while (s[loc] == '%')
		{
			while (check(s[loc + 1]) == 2)
				loc++;
			if (!check(s[loc + 1]))
			{
				lim++;
				break ;
			}
			len = len + ft_convert(s[loc + 1], args);
			loc = loc + 2;
		}
		if (s[loc] == '%' && s[loc + 1] == '\0' && lim == 1)
			return (-1);
		if (s[loc] == '\0')
			break ;
		ft_putchar_fd(s[loc++], 2);
		len++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		loc;
	int		len;
	va_list	args;

	if (!s)
		return (-1);
	loc = 0;
	len = 0;
	va_start(args, s);
	len = display(args, s, len, loc);
	va_end(args);
	return (len);
}
