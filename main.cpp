//
// Created by onekram on 11/1/23.
//

#include <iostream>
#include "parser.h"
#include "tsv_reader.h"

int main(int argc, char** argv) {
    Param parameters = parsingValues(argc, argv);
    PointNet pointNet = readFile(parameters.filenameInput);
    for (int i = 0; i < 3; ++i) {
        std::cout << pointNet.getPoint(i).x << " " << pointNet.getPoint(i).y << " " << pointNet.getPoint(i).value << std::endl;
    }
}
