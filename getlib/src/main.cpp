/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** getlib
*/

#include <iostream>
#include <fmt/format.h>
#include "../include/main.h"

int main() 
{
    try{
        getlib();
    }
    catch(Error &e){
        std::cerr << fmt::format("Error {}: {}", e.getNumber(), e.what());
        return 1;
    }
    return 0;
}
