#include "push_swap.h"

void	ft_lstend(t_stack **a, int num)
{
	t_stack	*tmp;
	t_stack	*end;

	tmp = ft_calloc(1, sizeof(t_stack));
	tmp->nb = num;
	tmp->next = NULL;
	if ((end = *a))
	{
		while (end->next)
			end = end->next;
		end->next = tmp;
	}
	else
		(*a) = tmp;


void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}



void	rep_check(t_stack *tmp, int n)
{
	while (tmp)
	{
		if (tmp->nb == n)
			ft_exit();
		tmp = tmp->next;
	}
}


t_stack		*get_numbers(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		n;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		rep_check(a, n);
		ft_lstend(&a, n);
        i++;
	}
	return (a);
}