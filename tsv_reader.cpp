//
// Created by onekram on 11/1/23.
//
#include <fstream>
#include <iostream>
#include <cstring>
#include "tsv_reader.h"


const int kMaxLineLength = 25;
const int kAmountParameters = 3;


uint64_t parseInt64U(const char* line){
    try {
        return std::stoul(line);
    } catch (const std::invalid_argument &ex) {
        std::cerr << "Error while parsing file: Value must be integer" << std::endl;
        exit(EXIT_FAILURE);
    } catch (const std::out_of_range  &ex) {
        std::cerr << "Error while parsing file: Value must be integer" << std::endl;
        exit(EXIT_FAILURE);
    }
}


int16_t parseInt16(const char* line){
    try {
        return (int16_t)std::stoi(line);
    } catch (const std::invalid_argument &ex) {
        std::cerr << "Error while parsing file: Value must be integer" << std::endl;
        exit(EXIT_FAILURE);
    } catch (const std::out_of_range  &ex) {
        std::cerr << "Error while parsing file: Value must be integer" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void putToPoint(Point& point, const int index, const char* value) {
    switch (index) {
        case 1:
            point.x = parseInt16(value);
            break;
        case 2:
            point.y = parseInt16(value);
            break;
        case 3:
            point.value = parseInt64U(value);
            break;
        default:
            break;
    }
}

uint64_t putPoint(Point*& pointNet, const Point& point, const uint64_t index, uint64_t size) {
    if (index + 1 > size) {
        size *= 2;
        auto* pointNetExt = new Point[size];
        std::memcpy(pointNetExt, pointNet, size);
        pointNet = pointNetExt;
    }
    pointNet[index] = point;
    return size;
}


Point parsingLine(const char* line, int length) {
    Point point{};
    int lastIndex = 0;
    int amount = 1;

    for (int i = 0; i < length; ++i) {
        if (line[i] == '\t' || i == length - 1) {
            char* el = new char[kMaxLineLength];
            std::strncpy(el, line + lastIndex, i);
            putToPoint(point, amount, el);
            lastIndex = i + 1;
            amount++;
        }
    }

    if (amount < kAmountParameters) {
        std::cerr << "Error while parsing file: to few values" << std::endl;
        exit(EXIT_FAILURE);
    }
    return point;
}
Point* readFile(const char* filenameInput) {
    uint64_t size = 100;
    uint64_t index = 0;
    auto* pointNet = new Point[size];
    std::ifstream in{filenameInput, std::ios::in};
    if (!in.is_open()) {
        std::cerr << "File no found " << filenameInput << std::endl;
        exit(EXIT_FAILURE);
    }

    for (char line[kMaxLineLength]; in.getline(line, kMaxLineLength, '\n'); index++) {
        Point point = parsingLine(line, (int)strlen(line));
        size = putPoint(pointNet, point, index, size);
    }
    return pointNet;
}