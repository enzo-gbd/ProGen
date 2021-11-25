#** EPITECH PROJECT, 2022
#** Makefile
#** File description:
#** getlib

SRC =	../src/main.cpp	\
		../src/getlib.cpp

OBJ_SRC  =	$(SRC:.cpp=.o)

CXXFLAGS =	-std=c++17

NAME     =   getlib

$(NAME): $(OBJ_SRC)
	g++ $(OBJ_SRC) -I./../include -Wall -Wextra -Werror -lstdc++ -L/usr/local/opt/llvm/lib -lfmt -o $(NAME) -g3

all:    $(NAME)

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
        