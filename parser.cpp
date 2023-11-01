//
// Created by onekram on 11/1/23.
//
#include <cstring>
#include <string>
#include <iostream>

#include "parser.h"

#define IS_INPUT_VALUE(value) (!strcmp(value, "-i") || !strcmp(value, "--input"))
#define IS_OUTPUT_VALUE(value) (!strcmp(value, "-o") || !strcmp(value, "--output"))
#define IS_MAX_ITERATION_VALUE(value) (!strcmp(value, "-m") || !strcmp(value, "--max-iter"))
#define IS_FREQUENCY_VALUE(value) (!strcmp(value, "-f") || !strcmp(value, "--freq"))

int isInt(const char* value) {
    try {
        return std::stoi(value);
    } catch (const std::invalid_argument &ex) {
        std::cerr << "Value must be integer" << std::endl;
        exit(EXIT_FAILURE);
    } catch (const std::out_of_range  &ex) {
        std::cerr << "Value must be integer" << std::endl;
        exit(EXIT_FAILURE);
    }
}
int putPair(Param& pair, char* name, char* value) {
    if (name[0] != '-') return -1;
    if (IS_INPUT_VALUE(name)) {
        pair.filenameInput = value;
        return 0;
    }
    if (IS_OUTPUT_VALUE(name)) {
        pair.pathOutput = value;
        return 0;
    }
    if (IS_MAX_ITERATION_VALUE(name)) {
        pair.maxIterations = isInt(value);
        return 0;
    }
    if (IS_FREQUENCY_VALUE(name) && isInt(value)) {
        pair.frequency = isInt(value);
        return 0;
    }
    return -1;
}

Param parsingValues(int argc, char** argv) {
    Param parameters{};
    int i = 1;
    while (i < argc) {
        if (i + 1 == argc) {
            std::cerr << "Put value for the parameter " <<  argv[i] << std::endl;
            exit(EXIT_FAILURE);
        }
        if (putPair(parameters, argv[i], argv[i + 1]) == -1) {
            std::cerr << "Unknown parameter " << argv[i] << std::endl;
            exit(EXIT_FAILURE);
        };
        i += 2;
    }
    return parameters;
}