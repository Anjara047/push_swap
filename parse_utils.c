/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanjara <tsanjara@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:25:46 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/26 23:20:19 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	affect(t_stack **a, char **argv, int *error, int loc)
{
	t_stack	*new;
	int		value;

	value = ft_atoi(argv[loc], error);
	new = ft_stack_new(value);
	if (!new)
	{
		ft_stackclear(a);
		return (1);
	}
	ft_add_stack_back(new, a);
	if (error[0] == 1)
	{
		ft_stackclear(a);
		return (1);
	}
	return (0);
}

int	f_affect(t_stack **a, char **argv, int *flag, int *error)
{
	int		loc;
	char	**split;

	loc = 1;
	while (argv[loc])
	{
		if (!(loc == flag[0] || loc == flag[1]))
		{
			if (check_arg(argv, loc) == 0)
			{
				split = ft_split(argv[loc], 32);
				error[0] = parse(split, a, flag, 0);
				free_split(split);
			}
			else if (affect(a, argv, error, loc) == 1)
				return (1);
		}
		loc++;
		if (error[0] == 1)
		{
			ft_stackclear(a);
			return (1);
		}
	}
	return (0);
}

int	s_affect(t_stack **a, char **argv, int *flag, int *error)
{
	int		loc;
	int		value;
	char	**split;
	t_stack	*new;

	loc = 0;
	while (argv[loc])
	{
		if (check_arg(argv, loc) == 0)
		{
			split = ft_split(argv[loc], 32);
			error[0] = parse(split, a, flag, 0);
			free_split(split);
		}
		else if (affect(a, argv, error, loc) == 1)
			return (1);
		loc++;
		if (error[0] == 1)
		{
			ft_stackclear(a);
			return (1);
		}
	}
	return (0);
}

void	free_split(char **str)
{
	int	loc;

	loc = 0;
	while (str[loc])
	{
		free(str[loc]);
		loc++;
	}
	free(str);
}
