/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:19:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/06 12:45:37 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int 	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = get_numbers(ac, av);
	b = NULL;
	get_commands(&a, &b);
	if (check(a, b))
		ft_putendl_fd("[OK]", 1);
	else
		ft_putendl_fd("[KO]", 1);
	ft_free(&a);
	ft_free(&b);
	return (0);
}
