//
// Created by onekram on 11/1/23.
//

#include <iostream>
#include "parser.h"

int main(int argc, char** argv) {
    Param parameters = parsingValues(argc, argv);
    std::cout << parameters.filenameInput << std::endl;
    std::cout << parameters.frequency << std::endl;
}
