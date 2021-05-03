#include "../../push_swap.h"

int     sort_stack(t_batch *batch)
{
    int ret;

    ret = 0;
    if(ft_listlen((*batch).a) <= 3)
        ret += ft_minisort(batch);
    else if (ft_listlen((*batch).a) <= 40)
		ret += ft_mediumsort(batch);
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
    //printf("Total moves = %d\n", ret);
    ft_free(&(batch.a));
	ft_free(&(batch.b));
    return (0);
}