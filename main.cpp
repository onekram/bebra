//
// Created by onekram on 11/1/23.
//

#include <iostream>
#include "parser.h"
#include "file_io.h"

int main(int argc, char** argv) {
    Param parameters = parsingValues(argc, argv);
    PointNet pointNet = readFile(parameters.filenameInput);
//    for (int i = 0; i < pointNet.getSize(); ++i) {
//        std::cout << pointNet.getPoint(i).x << " " << pointNet.getPoint(i).y << " " << pointNet.getPoint(i).value << std::endl;
//    }
    std::cout << std::endl;

//    pointNet.fillNet();
//    uint64_t** net = pointNet.getNet();
//
//    int len = pointNet.getLength();
//    int wid = pointNet.getWidth();
//
//
//    for (int i = 0; i < len; ++i) {
//        for (int j = 0; j < wid; ++j) {
//            std::cout << net[j][i] << " ";
//        }
//        std::cout << '\n';
//    }
    makeBMP(pointNet, 1);

}
