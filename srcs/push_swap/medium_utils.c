/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:08:58 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/05 11:17:01 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rot_loop(char stack, t_batch *batch, int c)
{
	int	i;

	i = -1;
	if (stack == 'a')
		while (++i < c)
			check_commands("ra", &(*batch).a, &(*batch).b, 1);
	else if (stack == 'b')
		while (++i < c)
			check_commands("rb", &(*batch).a, &(*batch).b, 1);
}

void	revrot_loop(char stack, t_batch *batch, int c)
{
	int	i;

	i = -1;
	if (stack == 'a')
		while (++i < c)
			check_commands("rra", &(*batch).a, &(*batch).b, 1);
	else if (stack == 'b')
		while (++i < c)
			check_commands("rrb", &(*batch).a, &(*batch).b, 1);
}

void	loop_c(char stack, t_batch *batch, int c)
{
	int	n;

	if (stack == 'a')
		n = ft_listlen((*batch).a);
	else
		n = ft_listlen((*batch).b);
	if (c <= n / 2)
		rot_loop(stack, batch, c);
	else
		revrot_loop(stack, batch, n - c);
}
