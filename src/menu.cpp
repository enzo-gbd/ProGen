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
        system("clear");
        std::cout << text;
        std::cin >> buff;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return buff;
    };

    while (lang != 1 && lang != 2) {
        lang = get_data(lang, R"(Quel est le language du projet: 
1: C
2: Cpp
)");
    }
    while (name.size() < 3 && name != "@") {
        name = get_data(name, "Quel est le nom du projet: ");
    }
    while (link.find("git@github.com:") == std::string::npos) {
        link = get_data(link, "Lien GitHub: ");
    }
    while (vs != "y" && vs != "n") {
        vs = get_data(link, "Voules vous ouvrir votre projet avec VsCode? (y or n): ");
    }
    system("clear");
    Project projet(lang, name, link, vs);
    return projet;
}