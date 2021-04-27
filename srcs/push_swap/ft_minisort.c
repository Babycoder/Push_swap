#include "../../push_swap.h"



int ft_issorted(t_stack *s)
{
	t_stack	*head;
	int		ret;

	ret = 0;
	head = s;
	while (s && s->next)
	{
		if (s->next->nb < s->nb)
			ret++;
		s = s->next;
	}
	if (head->nb < s->nb)
		ret++;
    if (ret > 1)
        return(0);
    else
        return (1);
}

int		ft_lstmin(t_stack *s)
{
	int min;

	min = 0;
	if (s)
		min = s->nb;
	while (s)
	{
		if (min > s->nb)
			min = s->nb;
		s = s->next;
	}
	return (min);
}

int ft_minisort(t_batch *batch)
{
    int ret;

    ret = 0;
    if(!ft_issorted((*batch).a))
    {
        check_commands("sa", &(*batch).a, &(*batch).b, 1);
        ret++;
    }

    
}