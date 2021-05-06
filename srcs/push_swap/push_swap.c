/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 03:12:54 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/06 02:48:17 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		check_commands("pa", a, b, 1);
	}
}

void	sort_stack(t_batch *batch)
{
	int i;
	int div;
	int chunk;

	chunk = 0;
	div = 0;
	i = 1;
	if (ft_listlen((*batch).a) <= 3)
		ft_minisort(batch);
	else if (ft_listlen((*batch).a) <= 40)
		ft_mediumsort(batch);
	else
	{
		if (ft_listlen((*batch).a) <= 200)
			div = 5;
		else
			div = 11;
	}
	if (div)
	{
		chunk = (ft_listmax((*batch).a) - ft_listmin((*batch).a)) / div;
		while(i <= div)
		{
			ft_chunksort(batch, chunk * i);
			i++;
		}
		push_to_a(&(*batch).a, &(*batch).b);
	}
}

int	main(int ac, char **av)
{
	t_batch	     batch;

	batch.a = get_numbers(ac, av);
	if (!batch.a)
		return (0);
	batch.b = NULL;
	sort_stack(&batch);
	ft_free(&(batch.a));
	ft_free(&(batch.b));
	return (0);
}
