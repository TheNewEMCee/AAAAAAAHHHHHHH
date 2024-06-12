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
    void setValue(int n);
    int getValue(bool updateValue = true);
    void setLineToReference(int line);
};

#endif //AAAAAAAHHHHHHH_CINT_H
