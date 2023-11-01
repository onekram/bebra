//
// Created by onekram on 11/1/23.
//

#include <iostream>
#include "parser.h"
#include "tsv_reader.h"

int main(int argc, char** argv) {
    Param parameters = parsingValues(argc, argv);
    Point* pointNet = readFile(parameters.filenameInput);
    for (int i = 0; i < 3; ++i) {
        std::cout << pointNet[i].x << " " << pointNet[i].y << " " << pointNet[i].value << std::endl;
    }
}
