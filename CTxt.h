#include <iostream>
#include "CFile.h"

#ifndef AAAAAAAHHHHHHH_CTXT_H
#define AAAAAAAHHHHHHH_CTXT_H

class CTxt : public CFile {
private:
    int numLines;
public:
    CTxt();
    CTxt(const std::string &name, const std::string &path);
    ~CTxt();
    void printFile(int start, int finish, int width = 32, bool isBeautified = true);
    void writeLine(std::string message, int lineToWrite);
    std::string readLine(int lineToRead);
    void printLine(int lineToPrint);
    bool isValidPath();

    void updateNumLines();
    int getNumLines();
};

#endif //AAAAAAAHHHHHHH_CTXT_H