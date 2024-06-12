#include <iostream>
#include <fstream>
#include "CFile.h"
#include "CTxt.h"
#ifndef AAAAAAAHHHHHHH_CVAR_H
#define AAAAAAAHHHHHHH_CVAR_H

class CVar {
protected:
    std::string name;
    CTxt txtFile;
    int lineToReference;
public:
    CVar();
    CVar(const std::string &name, CTxt txtFile, int lineToReference);
    CVar(const CVar &cv);
    ~CVar();
    void setName(std::string n);
    void setTxtFile(const CTxt &txtFile);

    virtual void setLineToReference(int l);
    std::string getName() const;
    CTxt getTxtFile() const;
    int getLineToReference() const;
    void printPathContents(int start, int finish, bool isBeautified = true);
};

#endif //AAAAAAAHHHHHHH_CVAR_H