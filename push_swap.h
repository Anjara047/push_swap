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

int		ft_atoi(char *nb);
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
void	indexing(t_stack **a);
int		find_min_value(t_stack	**a);
int		find_min_position(t_stack **a);
void	move_min_top(t_stack **a);
int		ft_sqrt(int	nbr);
void	simple_strategy(t_stack **a, t_stack **b);
void	medium_strategy(t_stack **a, t_stack **b);

#endif
