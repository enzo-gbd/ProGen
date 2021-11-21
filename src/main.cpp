#include <iostream>
#include <fmt/format.h>
#include "../include/main.h"

int main() 
{
    try{
        auto project = menu();
        project.Generate();
        project.Open();
    }
    catch(std::exception &e){
        std::cerr << fmt::format("Error: {}\n", e.what());
        return 1;
    }
    return 0;
}