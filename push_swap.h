/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:02:46 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/21 09:22:18 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

double	count_disorder(t_stack **a);
void	adaptive_strategy(t_stack **a, t_stack **b, double disorder);
int		check_flag(char *flag);
void	choose_strat(t_stack **a, t_stack **b, int flag);
void 	error_mess(void);
int		check_arg(char **argv, int loc);
int		ft_atoi(char *nb);
char	**ft_split(char const *s, char c);
t_stack	*ft_stack_new(int value);
t_stack *ft_stack_last(t_stack *a);
void	ft_stackclear(t_stack **a);
void	ft_add_stack_back(t_stack *new, t_stack **a);
void	sa_ab(t_stack **a);
void	pa_ab(t_stack **a, t_stack **b);
void	ra_ab(t_stack **a);
void	rra_ab(t_stack **a);
void	sb_ab(t_stack **b);
void	pb_ab(t_stack **a, t_stack **b);
void	rb_ab(t_stack **b);
void	rrb_ab(t_stack **b);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
int		count_size(t_stack *a);
void	indexing(t_stack **a, int size);
int		find_min_value(t_stack	**a);
int		find_min_position(t_stack **a);
void	move_min_top(t_stack **a);
int		ft_sqrt(int	nbr);
void	medium_strategy(t_stack **a, t_stack **b);
void	simple_strategy(t_stack **a, t_stack **b);
void	complex_strategy(t_stack **a, t_stack **b);

#endif
