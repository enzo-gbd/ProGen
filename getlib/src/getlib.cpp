#include "../include/main.h"
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <fmt/format.h>

bool is_nbr(std::string str)
{
    for (auto c : str) {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}

int get_nbr(std::string str)
{
    int nbr(0);
    if (is_nbr(str) && str.size() > 1)
        nbr = std::stoi(str);
    else if (is_nbr(str) && str.size() == 1)
        nbr = str.at(0) - '0';
    return nbr;
}

std::vector<int> get_index(int max, std::map<int, std::string> map)
{
    std::vector<int> index;
    int nbr;
    std::string line;

    do {
        system("clear");
        for (int i(1); i < max; i ++) {
            std::cout << fmt::format("{}. {}", i, map[i]) << std::endl;
        }
        std::cout << "\nEntrez les nombres correspondants séparés d'espaces (toute donnée invalide ne sera pas prise en compte): ";
        std::getline(std::cin, line);
        do {
            if (line.find_first_of(' ') == std::string::npos) {
                nbr = get_nbr(line);
                if (nbr > 0 && nbr < max)
                    index.push_back(nbr);
                break;
            } else {
                nbr = get_nbr(std::string(line.begin(), line.begin() + line.find_first_of(' ')));
                line = std::string(line.begin() + line.find_first_of(' ') + 1, line.end());
                if (nbr > 0 && nbr < max)
                    index.push_back(nbr);
            }
        } while (1);
    } while (index.begin() == index.end());
    return index;
}

std::string file_to_str(const char *reg, std::string file_path)
{
    std::string line;
    std::string res;
    std::ifstream file(file_path);
    std::ostringstream stream;

    while (std::getline(file, line))
    {
        if (line.find("/*") == std::string::npos && line.find("**") == std::string::npos && line.find("*/") == std::string::npos)
            stream << fmt::format(reg, line);
    }
    res = stream.str();
    return res;
}

void getlib()
{
    std::string files_index;
    auto [lib, max] = []() {
        int index(1);
        std::vector<std::string> tab;
        std::map<int, std::string> map;
        {
            std::ifstream file("ls.dat");
            std::istream_iterator<std::string> start(file);
            std::istream_iterator<std::string> end;
            std::back_insert_iterator<std::vector<std::string>> tab_it(tab);

            copy(start, end, tab_it);
        }
        if (tab.begin() == tab.end())
            throw(Error(404, "File is empty", 3));
        for (std::vector<std::string>::iterator it(tab.begin()); it != tab.end(); it++) {
            map[index] = *it;
            index++;
        }
        return std::make_tuple(map, index);
    }();
    auto [name, path] = []() {
        std::ifstream file(".prodata");
        std::string name;
        std::string path;

        file >> name;
        file >> path;
        return std::make_tuple(name, path);
    }();
    auto index = get_index(max, lib);
    for (auto nbr : index) {
        std::ofstream file(fmt::format("../{}", lib[nbr]).c_str());
        file << fmt::format(R"(/*
** EPITECH PROJECT, 2022
** {}
** File description:
** {}
*/
{})", lib[nbr], name, file_to_str("{}\n", fmt::format("../templates/{}", lib[nbr])));
        system(fmt::format("mv ../{} {}/lib/{}", lib[nbr], path, lib[nbr]).c_str());
    }
}