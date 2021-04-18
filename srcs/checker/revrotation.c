/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:40:51 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/18 12:40:53 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_stack **a, int x)
{
	if (x == 1)
		ft_putendl_fd("rra", 1);
	ft_revrot(a);
}

void	rrb(t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rrb", 1);
	ft_revrot(b);
}

void	rrr(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rrr", 1);
	ft_revrot(a);
	ft_revrot(b);
}
