//
// Created by onekram on 11/1/23.
//

#include <cstdint>

#ifndef LABWORK3_ONEKRAM_TSV_READER_H
#define LABWORK3_ONEKRAM_TSV_READER_H

#endif //LABWORK3_ONEKRAM_TSV_READER_H

struct Point {
    int16_t x, y;
    uint64_t value;
};

Point* readFile(const char* filenameInput);

