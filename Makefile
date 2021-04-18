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

SRC = srcs/checker/*.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:
	@make -C ./libft
	gcc -o checker $(SRC) ./libft/libft.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./checker
re: fclean all