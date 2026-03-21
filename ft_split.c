/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 03:01:01 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/19 22:48:42 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_free(char **str, size_t i)
{
	while (i > 0)
		free(str[--i]);
	return (0);
}

static void	insert(const char *s, char **str, char c)
{
	size_t	len2;
	size_t	loc;
	size_t	i;

	loc = 0;
	i = 0;
	while (s[loc])
	{
		while (s[loc] && s[loc] == c)
			loc++;
		if (!s[loc])
			break ;
		len2 = 0;
		while (s[loc] && (s[loc] != c))
			str[i][len2++] = s[loc++];
		str[i][len2] = '\0';
		i++;
	}
}

static int	alloc_it(const char *s, char **str, char c)
{
	size_t	len2;
	size_t	loc;
	size_t	i;

	loc = 0;
	i = 0;
	while (s[loc])
	{
		while (s[loc] && s[loc] == c)
			loc++;
		if (!s[loc])
			break ;
		len2 = 0;
		while (s[loc] && (s[loc] != c))
		{
			loc++;
			len2++;
		}
		str[i] = malloc(sizeof(char) * (len2 + 1));
		if (!str[i])
			return (ft_free(str, i));
		i++;
	}
	return (1);
}

static int	count(char const *s, char c)
{
	size_t	loc;
	int		nb;

	loc = 0;
	nb = 0;
	while (s[loc])
	{
		while (s[loc] && s[loc] == c)
			loc++;
		if (s[loc])
			nb++;
		while (s[loc] && (s[loc] != c))
			loc++;
	}
	return (nb);
}

char	**ft_split(char const *s, char c)
{
	int		nb;
	char	**strings;

	if (!s)
		return (NULL);
	nb = count(s, c);
	strings = malloc(sizeof(char *) * (nb + 1));
	if (!strings)
		return (NULL);
	strings[nb] = NULL;
	if (!alloc_it(s, strings, c))
	{
		free(strings);
		return (NULL);
	}
	insert(s, strings, c);
	return (strings);
}
