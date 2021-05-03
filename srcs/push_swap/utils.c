/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:55:51 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/03 00:18:51 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_checksort(t_stack *s)
{
	while (s && s->next)
	{
		if (s->nb > s->next->nb)
			return (0);
		s = s->next;
	}
	return (1);
}


int		ft_listmin(t_stack *s)
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

int		ft_listmax(t_stack *s)
{
	int	max;

	max = 0;
	if (s)
		max = s->nb;
	while (s)
	{
		if (max < s->nb)
			max = s->nb;
		s = s->next;
	}
	return (max);
}

int		ft_listlen(t_stack *s)
{
	int i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}