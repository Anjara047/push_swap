/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:17:46 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/25 07:07:05 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
char	*ft_itoa(int n);
int		ft_printptr(va_list args);
void	ft_putchar_fd(char c, int fd);
int		ft_putchar(va_list args);
int		ft_putdec(va_list args);
int		ft_puthex(va_list args);
int		ft_puthexup(va_list args);
int		ft_putint(va_list args);
void	ft_putnbr_fd(int n, int fd);
int		ft_putpercent(void);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr(va_list args);
int		ft_putudec(va_list args);
size_t	ft_strlen(const char *s);
int		print_double(va_list args);

#endif
