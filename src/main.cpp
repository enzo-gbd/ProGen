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
    catch(Error &e){
        std::cerr << fmt::format("Error {}: {}", e.getNumber(), e.what());
        return 1;
    }
    return 0;
}