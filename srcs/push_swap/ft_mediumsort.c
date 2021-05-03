/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediumsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:00:25 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/03 00:16:26 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


int	rot_loop(char stack, t_batch *batch, int c)
{
	int		i;
	int		ap;

	i = -1;
	ap = 0;
	if (stack == 'a')
		while (++i < c)
			ap += check_commands("ra", &(*batch).a, &(*batch).b, 1);
	else if (stack == 'b')
		while (++i < c)
			ap += check_commands("rb", &(*batch).a, &(*batch).b, 1);
	return (ap);
}

int revrot_loop(char stack, t_batch *batch, int c)
{
	int		i;
	int		ap;

	i = -1;
	ap = 0;
	if (stack == 'a')
		while (++i < c)
			ap += check_commands("rra", &(*batch).a, &(*batch).b, 1);
	else if (stack == 'b')
		while (++i < c)
			ap += check_commands("rrb", &(*batch).a, &(*batch).b, 1);
	return (ap);
}


int			loop_n(char stack, t_batch *batch, int c)
{
	int		n;
	int		ap;

	n = ft_listlen(stack == 'a' ? (*batch).a : (*batch).b);
	ap = 0;
	if (c <= n / 2)
		ap = rot_loop(stack, batch, c);
	else
		ap = revrot_loop(stack, batch, n - c);
	return (ap);
}

static int	fix_b(t_batch *batch)
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
	return (loop_n('b', batch, c));
}

int			prep_b(t_batch *batch)
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
	return (loop_n('b', batch, c));
}

static int	fix_a(t_batch *batch)
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
	return (loop_n('a', batch, c));
}

static int	prep_a(t_batch *batch)
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
	return (loop_n('a', batch, c));
}



int ft_mediumsort(t_batch *batch)
{
     int    ret;

     ret = 0;
    while (!ft_checksort((*batch).a) && ft_listlen((*batch).a) > 3)
	{
		ret += prep_b(batch);
		ret += check_commands("pb", &(*batch).a, &(*batch).b, 1);
	}
	ret += ft_minisort(batch);
	while ((*batch).b)
	{
		ret += prep_a(batch);
		ret += check_commands("pa", &(*batch).a, &(*batch).b, 1);
	}
	ret += fix_a(batch);
	return (ret);
}