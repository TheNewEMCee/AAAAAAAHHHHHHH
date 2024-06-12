#include <iostream>
#include <fstream>
#include "CFile.h"

#ifndef AAAAAAAHHHHHHH_CCPP_H
#define AAAAAAAHHHHHHH_CCPP_H


class CCpp : public CFile {
private:
    int numLines;
public:
    void printFileContents(int start, int finish, int width = 32, bool isBeautified = true);
    void updateNumLines();
    int getNumLines();
};

#endif //AAAAAAAHHHHHHH_CCPP_H
