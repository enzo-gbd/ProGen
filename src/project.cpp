#include "../include/main.h"
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <fmt/format.h>

using namespace std::string_literals;

auto curr_path = []() {
    std::string curr_path = std::filesystem::current_path().u8string();
    std::string path(curr_path.begin(), curr_path.begin() + curr_path.find("/ProGen"));
    return path;
}();

Project::Project()
{
}

Project::Project(int lang, std::string name, std::string link, std::string vs) : 
m_lang(lang), m_name(name), m_link(link), m_vs(vs)
{
    if (m_name == "@") {
        std::string::iterator start;
        std::string::iterator end;
        if (m_link.find("BDX") != std::string::npos)
            start = m_link.begin() + m_link.find("BDX") + 8;
        else
            throw Error(400, "Failed to find the project name, bad link format", 2);
        if (m_link.find_last_of("-") != std::string::npos)
            end = m_link.begin() + m_link.find_last_of("-");
        else
            throw Error(400, "Failed to find the project name, bad link format", 2);
        if (start > end)
            throw Error(404, "Failed to find the project name, bad link format");
        std::string name(start, end);
        std::cout << name << std::endl;
        m_name = name;
    }
}

void Project::Generate()
{
    std::filesystem::current_path(std::filesystem::path(curr_path));
    auto path = fmt::format("{}/{}", curr_path, [this]() {
        std::string::iterator start;
        std::string::iterator end;
        if (m_link.find("B-") != std::string::npos)
            start = m_link.begin() + m_link.find("B-");
        else
            throw Error(400, "Failed to find the repo name, bad link format", 3);
        if (m_link.find(".git") != std::string::npos)
            end = m_link.begin() + m_link.find(".git");
        else
            throw Error(400, "Failed to find the repo name, bad link format", 3);
        std::string repo(start, end);
        return repo;
    }());
    system(fmt::format("git clone {}", m_link).c_str());
    if ([path]() {
        std::ofstream file(fmt::format("{}/test", path));
        std::cout << fmt::format("{}/test", path) << std::endl;
        if (!file.is_open())
            return 1;
        else
            system(fmt::format("rm {}/test", path).c_str());
        return 0;
    }() == 1) {
        throw Error(400, "Failed to clone the repo", 3);
    }
    std::filesystem::current_path(std::filesystem::path(path));
    system("mkdir src include lib");
    system(fmt::format("cp {}/ProGen/bin/Normez.rb {}", curr_path, path).c_str());
    [this]() {
        std::ofstream file("Makefile");
        std::string args;
        std::string compil;
        if (!file.is_open())
            throw(Error(400, "Failed to create Makefile", 1));
        switch (static_cast<lang::project_lang>(m_lang)) {
        case lang::project_lang::C:
        {
            args = R"(SRC =	src/main.c

OBJ_SRC  =	$(SRC:.c=.o))";
            compil = "gcc $(OBJ_SRC) -I./../include -Wall -Wextra -Werror -o $(NAME)";
            break;
        }
        case lang::project_lang::Cpp:
        {
            args = R"(SRC =	src/main.cpp

OBJ_SRC  =	$(SRC:.cpp=.o)

CXXFLAGS =	-std=c++17)";
            compil = "g++ $(OBJ_SRC) -I./../include -Wall -Wextra -Werror -lstdc++ -L/usr/local/opt/llvm/lib -lfmt -o $(NAME)";
            break;
        }
        default:
            break;
        }
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
        )", m_name, args, m_name, compil);
        file.close();
    }();
    [this]() {
        std::ofstream file(".gitignore");
        if (!file.is_open())
            throw(Error(400, "Failed to create .gitignore", 1));
        file << "*.o\n.prodata\nmakefile_regen\nNormez.rb";
        file.close();
    }();
    [this, path]() {
        std::ofstream file(".prodata");
        if (!file.is_open())
            throw(Error(400, "Failed to create .prodata", 1));
        file << fmt::format("{}\n{}", m_name, path);
        file.close();
    }();
    [this]() {
        std::ofstream file("makefile_regen");
        std::string ext;
        if (!file.is_open())
            throw(Error(400, "Failed to create makefile_regen", 1));
        switch (static_cast<lang::project_lang>(m_lang)) {
        case lang::project_lang::C:
        {
            ext = "c";
            break;
        }
        case lang::project_lang::Cpp:
        {
            ext = "cpp";
            break;
        }
        default:
            break;
        }
        file << fmt::format(R"(touch ls.dat
echo src/*.{} > ls.dat
cp .prodata {}/ProGen/makefile_regen/bin
mv ls.dat {}/ProGen/makefile_regen/bin
cd {}/ProGen/makefile_regen/bin
make
./makefile_regen
make fclean
rm .prodata ls.dat
        )", ext, curr_path, curr_path, curr_path);
        file.close();
        system("chmod 777 makefile_regen");
    }();
    // on entre dans src
    std::filesystem::current_path(std::filesystem::path(fmt::format("{}/src", path)));
    [this]() {
        std::string path;
        std::string code;
        std::string includes;
        switch (static_cast<lang::project_lang> (m_lang)) {
            case lang::project_lang::C:
            {
                path = "main.c";
                code = "return 0;";
                includes = R"(#include "../include/main.h")";
                break;
            }
            case lang::project_lang::Cpp:
            {
                path = "main.cpp";
                code = R"(try{

    }
    catch(std::exception &e){
        std::cerr << fmt::format("Error: {}\n", e.what());
        return 1;
    }
    return 0;)";
                includes = R"(#include <iostream>
#include <fmt/format.h>
#include "../include/main.h")";
                break;
            }
            default:
                break;
        }
        std::ofstream file(path);
        if (!file.is_open())
            throw(Error(400, fmt::format("Failed to create {}", path), 1));
        file << fmt::format(R"(/*
** EPITECH PROJECT, 2022
** {}
** File description:
** {}
*/

{}

int main() 
{{
    {}
}}
)", path, m_name, includes, code);
        file.close();
    }();
    // on entre dans include
    std::filesystem::current_path(std::filesystem::path(fmt::format("{}/include", path)));
    [this]() {
        std::ofstream file("main.h");
        std::string includes;
        if (!file.is_open())
            throw(Error(400, "Failed to create main.h", 1));
        switch (static_cast<lang::project_lang> (m_lang)) {
            case lang::project_lang::C:
            {
                includes = " ";
                break;
            }
            case lang::project_lang::Cpp:
            {
                includes = R"(#include <iostream>
#include "error.h")";
                break;
            }
            default:
                break;
        }
        file << fmt::format(R"(/*
** EPITECH PROJECT, 2022
** main.h
** File description:
** {}
*/

{}
)", m_name, includes);
        file.close();
    }();
    switch (static_cast<lang::project_lang>(m_lang))
    {
    case lang::project_lang::C:
        break;
    case lang::project_lang::Cpp:
    {
        [this]() {
            std::ofstream file("error.h");
            if (!file.is_open())
                throw(Error(400, "Failed to create error.h", 1));
            file << fmt::format(R"(/*
** EPITECH PROJECT, 2022
** error.h
** File description:
** {}
*/

#include <exception>
#include <string>
 
class Error: public std::exception
{{
public:
    Error(int number = 0, std::string const& text = "", int level = 0) throw()
         : m_number(number), m_text(text), m_level(level)
    {{}}
 
     virtual const char* what() const throw()
     {{
         return m_text.c_str();
     }}
     
     int getNumber() const throw()
     {{
          return m_number;
     }}
    
    virtual ~Error() throw()
    {{}}
 
private:
    int m_number;               //Numéro de l'erreur
    std::string m_text;            //Description de l'erreur
    int m_level;               //Niveau de l'erreur
}};
)", m_name);
            file.close();
        }();
        break;
    }
    default:
        break;
    }
}

void Project::Open()
{
    if (m_vs == "y") {
        system(fmt::format("code {}/{}", curr_path, [this]() {
        std::string::iterator start;
        std::string::iterator end;
        if (m_link.find("B-") != std::string::npos)
            start = m_link.begin() + m_link.find("B-");
        else
            throw Error(400, "Failed to find the repo name, bad link format", 3);
        if (m_link.find(".git") != std::string::npos)
            end = m_link.begin() + m_link.find(".git");
        else
            throw Error(400, "Failed to find the repo name, bad link format", 3);
        std::string repo(start, end);
        return repo;
    }()).c_str());
    }
}

Project::~Project()
{
}