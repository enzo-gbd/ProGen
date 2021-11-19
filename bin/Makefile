SRC =	../src/main.cpp	\
		../src/menu.cpp	\
		../src/project.cpp

OBJ_SRC  =	$(SRC:.cpp=.o)

CXXFLAGS =	-std=c++17

NAME     =   ProGen

$(NAME): $(OBJ_SRC)
	g++ $(OBJ_SRC) -I./../include -Wall -Wextra -Werror -lstdc++ -L/usr/local/opt/llvm/lib -lfmt -o $(NAME)

all:    $(NAME)

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
        