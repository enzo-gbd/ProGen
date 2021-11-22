#include "../include/main.h"
#include <filesystem>
#include <vector>

Project menu()
{
    int lang(0);
    std::string name;
    std::string link;
    std::string vs;

    auto get_data = [](auto buff, auto text){
        std::cout << text;
        std::cin >> buff;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return buff;
    };

    system("clear");
    while (lang != 1 && lang != 2) {
        lang = get_data(lang, R"(Quel est le language du projet: 
1: C
2: Cpp
)");
        system("clear");
    }
    while ([name]() {
        if (name == "@")
            return true;
        if (name.empty() || name.size() < 3)
            return false;
        for (char c : name) {
            if (c < 33 || c == '\\')
                return false;
        }
        return true;
    }() == false) {
        system("clear");
        std::cout << R"(Le nom du projet doit:
-Contenir plus de 2 caractères ou etre un '@'(recherche automatique du nom dans le lien GitHub)
-Ne pas contenir de caractères non-affichables
-Ne pas contenir de '\'
(Attention, si le nom contient un espace, seul le premier mot sera pris en compte)
)" << std::endl;
        name = get_data(name, "Quel est le nom du projet: ");
    }
    system("clear");
    while ([link]() {
        if (link.find("git@github.com:EpitechIT") == std::string::npos || link.find("git@github.com:EpitechIT") != 0)
            return false;
        if (link.find(".git") + 4 != link.size())
            return false;
        return true;
    }() == false) {
        link = get_data(link, "Lien GitHub: ");
        system("clear");
        std::cout << "Le lien doit etre un lien GitHub Epitech\n" << std::endl;
    }
    system("clear");
    while (vs != "y" && vs != "n") {
        vs = get_data(link, "Voules vous ouvrir votre projet avec VsCode? (y or n): ");
        system("clear");
    }
    system("clear");
    Project projet(lang, name, link, vs);
    return projet;
}