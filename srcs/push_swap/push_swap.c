/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 03:12:54 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/03 03:13:37 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void     sort_stack(t_batch *batch)
{
    if(ft_listlen((*batch).a) <= 3)
        ft_minisort(batch);
    else if (ft_listlen((*batch).a) <= 40)
		ft_mediumsort(batch);
}



int     main(int ac, char **av)
{
    t_batch batch;

    batch.a = get_numbers(ac, av);
    if (!batch.a)
        return(0);
    batch.b = NULL;
    sort_stack(&batch);
    //printf("Total moves = %d\n", ret);
    ft_free(&(batch.a));
	ft_free(&(batch.b));
    return (0);
}