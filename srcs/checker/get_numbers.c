/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:19:34 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/05 13:27:11 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_pushend(t_stack **a, int num)
{
	t_stack	*tmp;
	t_stack	*end;

	tmp = malloc(sizeof(t_stack));
	tmp->nb = num;
	tmp->next = NULL;
	end = *a;
	if (end)
	{
		while (end->next)
			end = end->next;
		end->next = tmp;
	}
	else
		(*a) = tmp;
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	rep_check(t_stack *tmp, int n)
{
	while (tmp)
	{
		if (tmp->nb == n)
			ft_exit();
		tmp = tmp->next;
	}
}

int 	ft_truenb(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

t_stack 	*get_numbers(int ac, char **av)
{
	t_stack	*a;
	int		i;
	long int		n;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		if (!ft_truenb(av[i]))
			ft_exit();
		n = ft_atoi(av[i]);
		if (n == 2147483649)
			ft_exit();
		rep_check(a, n);
		ft_pushend(&a, n);
		i++;
	}
	return (a);
}
