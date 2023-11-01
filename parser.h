//
// Created by onekram on 11/1/23.
//

#ifndef LABWORK3_ONEKRAM_PARSER_H
#define LABWORK3_ONEKRAM_PARSER_H

#endif //LABWORK3_ONEKRAM_PARSER_H

struct Param {
    char* filenameInput;
    char* pathOutput;
    long maxIterations;
    long frequency;
};

Param parsingValues(int argc, char** argv);
