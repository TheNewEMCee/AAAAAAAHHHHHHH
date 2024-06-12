#include <fstream>
#include <string>
#include <utility>
#include "CVar.h"
#include "CFile.h"
#include "CTxt.h"


CVar::CVar() {}

CVar::CVar(const std::string &name, CTxt txtFile, int lineToReference) {
    this->setName(name);
    this->setTxtFile(txtFile);
    this->setLineToReference(lineToReference);
}

CVar::CVar(const CVar &cv) {
    this->setName(cv.getName());
    this->setTxtFile(cv.getTxtFile());
    this->lineToReference = cv.getLineToReference();
}

CVar::~CVar() {
    std::cout << "CVar " << this->name << " destroyed." << std::endl;
}

void CVar::setName(std::string n) {
    this->name = std::move(n);
}

void CVar::setTxtFile(const CTxt &txtFile) {
    this->txtFile = txtFile;
}

void CVar::setLineToReference(int l) {
    this->lineToReference = l;
}

std::string CVar::getName() const {
    return this->name;
}
CTxt CVar::getTxtFile() const {
    return this->txtFile;
}

int CVar::getLineToReference() const {
    return this->lineToReference;
}

