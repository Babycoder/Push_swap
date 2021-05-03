/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediumsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:00:25 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/03 03:22:20 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


void	rot_loop(char stack, t_batch *batch, int c)
{
	int		i;

	i = -1;
	if (stack == 'a')
		while (++i < c)
			check_commands("ra", &(*batch).a, &(*batch).b, 1);
	else if (stack == 'b')
		while (++i < c)
			check_commands("rb", &(*batch).a, &(*batch).b, 1);
}

void revrot_loop(char stack, t_batch *batch, int c)
{
	int		i;

	i = -1;
	if (stack == 'a')
		while (++i < c)
			check_commands("rra", &(*batch).a, &(*batch).b, 1);
	else if (stack == 'b')
		while (++i < c)
			check_commands("rrb", &(*batch).a, &(*batch).b, 1);
}


void			loop_n(char stack, t_batch *batch, int c)
{
	int		n;

	n = ft_listlen(stack == 'a' ? (*batch).a : (*batch).b);
	if (c <= n / 2)
		rot_loop(stack, batch, c);
	else
		revrot_loop(stack, batch, n - c);
}

void	fix_b(t_batch *batch)
{
	int		c;
	int		max;
	t_stack	*tmp;

	tmp = (*batch).b;
	max = ft_listmax((*batch).b);
	c = 0;
	while (tmp)
	{
	    if (tmp->nb == max)
            break;
		c++;
		tmp = tmp->next;
	}
	loop_n('b', batch, c);
}

void			prep_b(t_batch *batch)
{
	t_stack *tmp;
	int		c;

	c = 0;
	tmp = (*batch).b;
	if (((*batch).a)->nb < ft_listmin((*batch).b) ||
			((*batch).a)->nb > ft_listmax((*batch).b))
		return (fix_b(batch));
	while (tmp)
	{
		c++;
		if (tmp->next && (((*batch).a)->nb < tmp->nb &&
					((*batch).a)->nb > tmp->next->nb))
			break ;
		tmp = tmp->next;
	}
	loop_n('b', batch, c);
}

void	fix_a(t_batch *batch)
{
	int		c;
	int		min;
	t_stack	*tmp;

	tmp = (*batch).a;
	min = ft_listmin((*batch).a);
	c = 0;
	while (tmp)
	{
		if(tmp->nb == min)
			break;
		c++;
		tmp = tmp->next;
	}
	loop_n('a', batch, c);
}

void	prep_a(t_batch *batch)
{
	t_stack	*tmp;
	int		c;

	c = 0;
	tmp = (*batch).a;
	if (((*batch).b)->nb < ft_listmin(tmp) ||
			(((*batch).b)->nb) > ft_listmax(tmp))
		return (fix_a(batch));
	while (tmp)
	{
		c++;
		if (tmp->next && ((*batch).b)->nb > tmp->nb &&
				(((*batch).b)->nb) < tmp->next->nb)
			break ;
		tmp = tmp->next;
	}
	loop_n('a', batch, c);
}



void ft_mediumsort(t_batch *batch)
{
    while (!ft_checksort((*batch).a) && ft_listlen((*batch).a) > 3)
	{
		prep_b(batch);
		check_commands("pb", &(*batch).a, &(*batch).b, 1);
	}
	ft_minisort(batch);
	while ((*batch).b)
	{
		prep_a(batch);
		check_commands("pa", &(*batch).a, &(*batch).b, 1);
	}
	fix_a(batch);
}