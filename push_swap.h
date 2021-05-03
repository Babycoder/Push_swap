/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:19:53 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/03 03:11:41 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

/************ STACK ****************/

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct		s_batch
{
	t_stack			*a;
	t_stack			*b;
}					t_batch;

/************ INSTRUCTIONS ****************/

void		sa(t_stack **a, int x);
void		sb(t_stack **b, int x);
void		ss(t_stack **a, t_stack **b, int x);
void		pa(t_stack **a, t_stack **b, int x);
void		pb(t_stack **a, t_stack **b, int x);
void		ra(t_stack **a, int x);
void		rb(t_stack **b, int x);
void		rr(t_stack **a, t_stack **b, int x);
void		rra(t_stack **a, int x);
void		rrb(t_stack **b, int x);
void		rrr(t_stack **a, t_stack **b, int x);
void		ft_swaptop(t_stack **stack);
void		ft_push(t_stack **a, t_stack **b);
void		ft_rotation(t_stack **stack);
void		ft_revrot(t_stack **stack);

/*********** CHECKER ***************/

t_stack		*get_numbers(int ac, char **av);
void		rep_check(t_stack *tmp, int n);
void		ft_pushend(t_stack **a, int num);
void		ft_exit(void);
int			ft_search(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			check(t_stack *a, t_stack *b);
void			check_commands(char *cmd, t_stack **a, t_stack **b, int x);
void		get_commands(t_stack **a, t_stack **b);
int			check(t_stack *a, t_stack *b);
void		ft_free(t_stack **s);
int			ft_truenb(char *s);


/*********** Push_Swap  ***********/

int		ft_issorted(t_stack *s);
int 	ft_checksort(t_stack *s);
int		ft_listlen(t_stack *s);
int		ft_listmin(t_stack *s);
int		ft_listmax(t_stack *s);
int		ft_checksort(t_stack *s);
int		ft_minisort(t_batch *batch);
int		ft_mediumsort(t_batch *t_batch);



#endif