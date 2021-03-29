#include "push_swap.h"










int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
        return(0);
	a = get_numbers(ac, av);
	b = NULL;
	commands(&a, &b);
	ft_putendl(check(a, b) ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m");
	ft_lstfree(&a);
	ft_lstfree(&b);
	return (0);
}