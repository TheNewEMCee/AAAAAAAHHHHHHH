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
    void printFileContents(int start, int finish, int width = 32, bool isBeautified = true);
    void updateNumLines();
    int getNumLines();
};

#endif //AAAAAAAHHHHHHH_CTXT_H