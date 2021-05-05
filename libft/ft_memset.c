/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:12:22 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/05 17:22:58 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *argv, int x, size_t n)
{
	unsigned char	*temp;

	temp = argv;
	while (n--)
	{
		*temp++ = (unsigned char)x;
	}
	return (argv);
}
