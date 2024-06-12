#include <iostream>
#include <fstream>
#include <vector>
#ifndef AAAAAAAHHHHHHH_CFILE_H
#define AAAAAAAHHHHHHH_CFILE_H

class CFile {
private:
    std::string name;
    std::string path;
public:
    CFile();
    CFile(const std::string &name, const std::string &path);
    CFile(const CFile &cf);
    ~CFile();
    void setName(std::string n);
    void setPath(std::string p);
    std::string getName() const;
    std::string getPath() const;
};

#endif //AAAAAAAHHHHHHH_CFILE_H
