//
// Created by onekram on 11/3/23.
//
#include <cstring>
#include <fstream>
#include <iostream>
#include "PointNet.h"

void makeBMP(PointNet& pointNet, int iter) {


    std::ofstream file("SandPile.bmp", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "File no found " << "SandPile.bmp" << std::endl;
        exit(EXIT_FAILURE);
    }

    int length = pointNet.getLength();
    int width = pointNet.getWidth();

    int8_t padding =
            static_cast<uint8_t>((4 - (width / 2 + width % 2) % 4) % 4);
    uint64_t file_size =
            14 + 40 + 20 + (width / 2 + width % 2) * length + padding * length;
    uint32_t offset = 14 + 40 + 20;
    uint32_t header_size = 40;
    uint32_t zero = 0;
    file.write("BM", 2);
    file.write(reinterpret_cast<char*>(&file_size), 8);
    file.write(reinterpret_cast<char*>(&offset), 4);
    file.write(reinterpret_cast<char*>(&header_size), 4);
    file.write(reinterpret_cast<char*>(&width), 4);
    file.write(reinterpret_cast<char*>(&length), 4);

    uint16_t planes = 1;
    file.write(reinterpret_cast<char*>(&planes), 2);

    uint16_t bits_per_pixel = 4;
    file.write(reinterpret_cast<char*>(&bits_per_pixel), 2);

    file.write(reinterpret_cast<char*>(&zero), 4);

    file.write(reinterpret_cast<char*>(&zero), 4);

    file.write(reinterpret_cast<char*>(&zero), 4);
    file.write(reinterpret_cast<char*>(&zero), 4);

    uint32_t colors = 5;
    file.write(reinterpret_cast<char*>(&colors), 4);

    file.write(reinterpret_cast<char*>(&zero), 4);

    // white
    file.write("\xff\xff\xff\x00", 4);
    // green #27AE60
    file.write("\x60\xae\x27\x00", 4);
    // yellow #F1C40F
    file.write("\x0f\xc4\xf1\x00", 4);
    // purple #8E44AD
    file.write("\xad\x44\x8e\x00", 4);
    // black #232323
    file.write("\x23\x23\x23\x00", 4);

    // write pixels
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = 0; j < width / 2; ++j) {
            uint8_t pixel = 0;
            pixel |= ((pointNet.getNet()[i][2 * j] > 3) ? 4 : pointNet.getNet()[i][2 * j]) << 4;
            pixel |= ((pointNet.getNet()[i][2 * j + 1] > 3) ? 4 : pointNet.getNet()[i][2 * j + 1]);
            file.write(reinterpret_cast<char*>(&pixel), 1);
        }
        if (width % 2 == 1) {
            uint8_t pixel = 0;
            pixel |= ((pointNet.getNet()[i][width - 1] > 3) ? 4 : pointNet.getNet()[i][width - 1]) << 4;
            file.write(reinterpret_cast<char*>(&pixel), 1);
        }
        for (size_t j = 0; j < padding; ++j) {
            file.write("\x00", 1);
        }
    }

}