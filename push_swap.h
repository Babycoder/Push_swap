#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct		s_stack
{
	int			nb;
	struct s_stack	*next;
}					t_stack;


#endif