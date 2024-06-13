#include <iostream>
#include <fstream>
#include "CVar.h"

#ifndef AAAAAAAHHHHHHH_CINT_H
#define AAAAAAAHHHHHHH_CINT_H

class CInt : public CVar {
private:
    int value;
public:
    CInt();
    CInt(std::string &s);
    CInt(CInt &ci); // Copy
    CInt(std::string name, CTxt txtFile, int lineToReference, int value, bool getFromConst = true);
    ~CInt();
    void updateValue();
    void downloadValue();
    void uploadValue();
    void setValue(int n, bool updateFile = true);
    int getValue(bool updateValue = false);
    void setLineToReference(int line);
};

#endif //AAAAAAAHHHHHHH_CINT_H
