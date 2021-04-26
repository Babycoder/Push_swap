#include "../../push_swap.h"

int		ft_listlen(t_stack *x)
{
	int i;

	i = 0;
	while (x)
	{
		x = x->next;
		i++;
	}
	return (i);
}

int     sort_stack(t_batch *batch)
{
    int ret;

    ret = 0;
    if(ft_listlen((*batch).a) <= 3)
        ret = mini_sort(batch);
    return(ret);
}



int     main(int ac, char **av)
{
    int ret;
    t_batch batch;

    batch.a = get_numbers(ac, av);
    if (!batch.a)
        return(0);
    batch.b = NULL;
    ret = sort_stack(&batch);
    ft_free(&(batch.a));
	ft_free(&(batch.b));
    return (0);
}