#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

/************ STACK ****************/

typedef struct		s_stack
{
	int			nb;
	struct s_stack	*next;
}					t_stack;

/************ INSTRUCTIONS ****************/

void	sa(t_stack **a, int x);
void	sb(t_stack **b, int x);
void	ss(t_stack **a, t_stack **b, int x);
void	pa(t_stack **a, t_stack **b, int x);
void	pb(t_stack **a, t_stack **b, int x);
void	ra(t_stack **a, int x);
void	rb(t_stack **b, int x);
void	rr(t_stack **a, t_stack **b, int x);
void	rra(t_stack **a, int x);
void	rrb(t_stack **b, int x);
void	rrr(t_stack **a, t_stack **b, int x);

void	ft_swaptop(t_stack **stack);
void	ft_lstpush(t_stack **a, t_stack **b);
void	ft_lstrot(t_stack **stack);
void	ft_lstrevrot(t_stack **stack);




/*********** CHECKER ***************/

t_stack		*get_numbers(int ac, char **av);
void		rep_check(t_stack *tmp, int n);
void		ft_lstend(t_stack **a, int num);
void		ft_out(void);
int			ft_search(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			check(t_stack *a, t_stack *b);


#endif