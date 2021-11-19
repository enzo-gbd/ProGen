#include <iostream>
#include "../include/main.h"

int main() 
{
    try{
        auto project = menu();
        project.Generate();
        project.Open();
    }
    catch(std::exception &e){
        return 1;
    }
    return 0;
}