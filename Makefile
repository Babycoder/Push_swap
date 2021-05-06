# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 10:15:58 by ayghazal          #+#    #+#              #
#    Updated: 2021/05/06 12:08:38 by ayghazal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = srcs/checker/checker.c
PUSHSWAP = srcs/push_swap/push_swap.c

NAME = checker push_swap
#N2 = push_swap


SRC =	srcs/checker/ft_strcmp.c \
		srcs/checker/get_numbers.c \
		srcs/checker/instructions.c \
		srcs/checker/move.c \
		srcs/checker/revrotation.c \
		srcs/checker/rotation.c \
		srcs/checker/tools.c \
		srcs/push_swap/ft_minisort.c \
		srcs/push_swap/ft_mediumsort.c \
		srcs/push_swap/utils.c \
		srcs/push_swap/medium_utils.c \
		srcs/push_swap/ft_chunksort.c \
		
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	gcc -o checker $(CHECKER) $(SRC) ./libft/libft.a
	gcc -o push_swap $(PUSHSWAP) $(SRC) ./libft/libft.a

clean:
	rm -rf $(OBJ)
	@make re -C ./libft

fclean: clean
	rm -rf ./checker
	rm -rf ./push_swap
	@make fclean -C ./libft
re: fclean all