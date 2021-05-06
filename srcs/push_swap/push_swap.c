/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 03:12:54 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/06 15:57:50 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_div(int len)
{
	if (len <= 200)
		return (5);
	else
		return (11);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		check_commands("pa", a, b, 1);
	}
}

void	sort_stack(t_batch *batch)
{
	int	i;
	int	div;
	int	chunk;

	chunk = 0;
	div = 0;
	i = 0;
	if (ft_listlen((*batch).a) <= 3)
		ft_minisort(batch);
	else if (ft_listlen((*batch).a) <= 40)
		ft_mediumsort(batch);
	else
		div = get_div(ft_listlen((*batch).a));
	if (div)
	{
		chunk = (ft_listmax((*batch).a) - ft_listmin((*batch).a)) / div;
		while (++i < div)
			ft_chunksort(batch, chunk * i);
		ft_chunksort(batch, ft_listmax((*batch).a) + 1);
		push_to_a(&(*batch).a, &(*batch).b);
	}
}

int	main(int ac, char **av)
{
	t_batch	batch;

	batch.a = get_numbers(ac, av);
	if (!batch.a)
		return (0);
	batch.b = NULL;
	sort_stack(&batch);
	ft_free(&(batch.a));
	ft_free(&(batch.b));
	return (0);
}
