/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 00:59:44 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/06 01:08:06 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int ft_instack(t_stack *s, int chunk)
{
	while (s)
	{
		if (s->nb <= chunk)
			return (1);
		s = s->next;
	}
	return (0);
}

void    ft_chunksort(t_batch *batch, int chunk)
{
    while ((((*batch).a) && ft_instack((*batch).a, chunk)))
	{
		if (((*batch).a)->nb <= chunk)
		{
			prep_b(batch);
			check_commands("pb", &(*batch).a, &(*batch).b, 1);
		}
		else
			check_commands("ra", &(*batch).a, &(*batch).b, 1);
	}
	fix_b(batch);
}