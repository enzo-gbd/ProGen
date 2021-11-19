#** EPITECH PROJECT, 2022
#** Makefile
#** File description:
#** makefile_regen

SRC =	../src/main.cpp	\
		../src/regen.cpp

OBJ_SRC  =	$(SRC:.cpp=.o)

CXXFLAGS =	-std=c++17

NAME     =   makefile_regen

$(NAME): $(OBJ_SRC)
	g++ $(OBJ_SRC) -I./../include -Wall -Wextra -Werror -lstdc++ -L/usr/local/opt/llvm/lib -lfmt -o $(NAME)

all:    $(NAME)

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
        