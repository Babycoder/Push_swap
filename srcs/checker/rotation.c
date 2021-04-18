/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:39:23 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/18 12:39:42 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_stack **a, int x)
{
	if (x == 1)
		ft_putendl_fd("ra", 1);
	ft_rotation(a);
}

void	rb(t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rb", 1);
	ft_rotation(b);
}

void	rr(t_stack **a, t_stack **b, int x)
{
	if (x == 1)
		ft_putendl_fd("rr", 1);
	ft_rotation(a);
	ft_rotation(b);
}
