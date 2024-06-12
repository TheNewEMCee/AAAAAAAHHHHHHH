#include <iostream>
#include <fstream>
#include "CVar.h"

#ifndef AAAAAAAHHHHHHH_CSTRING_H
#define AAAAAAAHHHHHHH_CSTRING_H

class CString : public CVar {
private:
    std::string value;
public:
    CString();
    CString(std::string &s);
    CString(CString &ci); // Copy
    CString(std::string name, CTxt txtFile, int lineToReference, std::string value, bool getFromConst = true);
    ~CString();
    void updateValue();
    void setValue(std::string v);
    std::string getValue(bool updateValue = true);
    void setLineToReference(int line);
};

#endif //AAAAAAAHHHHHHH_CSTRING_H
