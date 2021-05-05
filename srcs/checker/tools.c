/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 03:11:23 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/05 11:11:35 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_commands(char *cmd, t_stack **a, t_stack **b, int x)
{
	if (ft_strcmp(cmd, "sa") == 0)
		sa(a, x);
	else if (ft_strcmp(cmd, "sb") == 0)
		sb(b, x);
	else if (ft_strcmp(cmd, "ss") == 0)
		ss(a, b, x);
	else if (ft_strcmp(cmd, "pa") == 0)
		pa(a, b, x);
	else if (ft_strcmp(cmd, "pb") == 0)
		pb(a, b, x);
	else if (ft_strcmp(cmd, "ra") == 0)
		ra(a, x);
	else if (ft_strcmp(cmd, "rb") == 0)
		rb(b, x);
	else if (ft_strcmp(cmd, "rr") == 0)
		rr(a, b, x);
	else if (ft_strcmp(cmd, "rra") == 0)
		rra(a, x);
	else if (ft_strcmp(cmd, "rrb") == 0)
		rrb(b, x);
	else if (ft_strcmp(cmd, "rrr") == 0)
		rrr(a, b, x);
	else
		ft_exit();
}

void	get_commands(t_stack **a, t_stack **b)
{
	char	*str;

	while (get_next_line(0, &str) > 0)
	{
		check_commands(str, a, b, 0);
		free(str);
	}
	if (str && *str)
		free(str);
}

int 	check(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a && a->next)
	{
		if (a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_free(t_stack **s)
{
	t_stack	*tmp;

	while (*s)
	{
		tmp = *s;
		tmp->nb = 0;
		(*s) = (*s)->next;
		free(tmp);
	}
}
