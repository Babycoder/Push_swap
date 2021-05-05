/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:44:39 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/05 12:26:38 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_issorted(t_stack *s)
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
		return (0);
	else
		return (1);
}

void	ft_minisort(t_batch *batch)
{
	if (!ft_issorted((*batch).a))
		check_commands("sa", &(*batch).a, &(*batch).b, 1);
	if (((*batch).a)->nb != ft_listmin((*batch).a))
	{
		if (((*batch).a)->next->nb == ft_listmin((*batch).a))
			check_commands("ra", &(*batch).a, &(*batch).b, 1);
		else
			check_commands("rra", &(*batch).a, &(*batch).b, 1);
	}
}
