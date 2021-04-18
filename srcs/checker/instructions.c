/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:20:16 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/18 10:20:17 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stack **a, int x)
{
	if (x == 1)
		ft_putendl_fd("sa", 1);
	ft_swaptop(a);
}

void	sb(t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("sb", 1);
	ft_swaptop(b);
}

void	ss(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("ss", 1);
	ft_swaptop(a);
	ft_swaptop(b);
}

void	pa(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("pa", 1);
	ft_push(a, b);
}

void	pb(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("pb", 1);
	ft_push(b, a);
}
