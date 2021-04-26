# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 10:15:58 by ayghazal          #+#    #+#              #
#    Updated: 2021/04/18 10:16:00 by ayghazal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = srcs/checker/checker.c
PUSHSWAP = srcs/push_swap/push_swap.c



SRC =	srcs/checker/ft_strcmp.c \
		srcs/checker/get_numbers.c \
		srcs/checker/instructions.c \
		srcs/checker/move.c \
		srcs/checker/revrotation.c \
		srcs/checker/rotation.c \

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all:
	@make -C ./libft
	gcc -o checker $(CHECKER) $(SRC) ./libft/libft.a
	gcc -o push_swap $(PUSHSWAP) $(SRC) ./libft/libft.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./checker
	rm -rf ./push_swap
re: fclean all