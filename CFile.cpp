#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include "CFile.h"

CFile::CFile() = default;
CFile::CFile(const std::string &name, const std::string &path) {
    this->setName(name);
    this->setPath(path);
}
CFile::CFile(const CFile &cf) {
    this->setName(cf.getName());
    this->setPath(cf.getPath());
}
CFile::~CFile() {
    //std::cout << "CFile " << this->getName() << " at " << this->getPath() << " destroyed." << std::endl;
}
void CFile::setName(std::string n) {
    this->name = std::move(n);
}
void CFile::setPath(std::string p) {
    this->path = std::move(p);
}
std::string CFile::getName() const {
    return this->name;
}
std::string CFile::getPath() const {
    return this->path;
}