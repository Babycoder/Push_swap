SRC = *.c
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