/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:19:43 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/18 10:19:44 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_swaptop(t_stack **stack)
{
	t_stack	*temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		*stack = temp;
	}
}

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = temp;
	}
}

void	ft_rotation(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		last = (*stack);
		temp = (*stack)->next;
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = last;
		last->next = NULL;
		(*stack) = temp;
	}
}

void	ft_revrot(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;

	if (*stack && (*stack)->next)
	{
		temp = (*stack);
		while (*stack && (*stack)->next && (*stack)->next->next)
			(*stack) = (*stack)->next;
		first = (*stack)->next;
		(*stack)->next = NULL;
		first->next = temp;
		(*stack) = first;
	}
}
