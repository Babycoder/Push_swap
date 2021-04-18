#include "push_swap.h"

void	sa(t_stack **a, int x)
{
	if (x == 1)
		ft_putendl_fd("sa", 1);
	ft_swaptop(a);
}

void	sb(t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("sb", 1);
	ft_swaptop(b);
}

void	ss(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("ss", 1);
	ft_swaptop(a);
	ft_swaptop(b);
}

void	pa(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("pa", 1);
	ft_lstpush(a, b);
}

void	pb(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("pb", 1);
	ft_lstpush(b, a);
}

void	ra(t_stack **a, int x)
{
	if (x == 1)
		ft_putendl_fd("ra", 1);
	ft_lstrot(a);
}

void	rb(t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rb", 1);
	ft_lstrot(b);
}

void	rr(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rr", 1);
	ft_lstrot(a);
	ft_lstrot(b);
}

void	rra(t_stack **a, int x)
{
	if (x == 1)
		ft_putendl_fd("rra", 1);
	ft_lstrevrot(a);
}

void	rrb(t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rrb", 1);
	ft_lstrevrot(b);
}

void	rrr(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rrr", 1);
	ft_lstrevrot(a);
	ft_lstrevrot(b);
}