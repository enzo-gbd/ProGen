#include "../include/main.h"
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <fmt/format.h>

void regen()
{
    auto ls = []() {
        std::vector<std::string> tab;
        std::string res;
        std::ifstream file("ls.dat");

        std::istream_iterator<std::string> start(file);
        std::istream_iterator<std::string> end;
        std::back_insert_iterator<std::vector<std::string>> b_it(tab);
        std::ostringstream stream;

        copy(start, end, b_it);
        if (tab.begin() == tab.end())
            throw(Error(404, "File is empty", 3));
        for (std::vector<std::string>::iterator it(tab.begin()); it != tab.end(); it++) {
            stream << fmt::format("{}\t\\\n\t\t", *it);
        }
        res = stream.str();
        return res;
    }();
    auto [name, path] = []() {
        std::ifstream file(".prodata");
        std::string name;
        std::string path;

        file >> name;
        file >> path;
        return std::make_tuple(name, path);
    }();
    std::ofstream file("../res/Makefile");
    std::string args;
    std::string compil;
    if (!file.is_open())
        throw(Error(400, "Failed to create Makefile", 1));
    if (ls.find(".cpp") == std::string::npos && ls.find(".c") != std::string::npos) {
        args = fmt::format(R"(SRC =	{}

OBJ_SRC  =	$(SRC:.c=.o))", ls);
        compil = "gcc $(OBJ_SRC) -I./../include -Wall -Wextra -Werror -o $(NAME)";
    } else if (ls.find(".c ") == std::string::npos && ls.find(".cpp") != std::string::npos) {
        args = fmt::format(R"(SRC =	{}

OBJ_SRC  =	$(SRC:.cpp=.o)

CXXFLAGS =	-std=c++17)", ls);
        compil = "g++ $(OBJ_SRC) -I./../include -Wall -Wextra -Werror -lstdc++ -L/usr/local/opt/llvm/lib -lfmt -o $(NAME)";
    } else
        throw(Error(400, "Bad type of files\n", 2));
    file << fmt::format(R"(#** EPITECH PROJECT, 2022
#** Makefile
#** File description:
#** {}

{}

NAME     =   {}

$(NAME): $(OBJ_SRC)
	{}

all:    $(NAME)

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
        )", name, args, name, compil);
    system(fmt::format("mv ../res/Makefile {}", path).c_str());
    file.close();
}