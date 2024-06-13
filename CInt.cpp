#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include <unistd.h>
#include "CInt.h"
#include "CVar.h"
#include "CFile.h"
#include "CTxt.h"

CInt::CInt() : CVar() {
    this->name = "Unnamed CInt";
    this->lineToReference = 0;
    this->value = 0;
}
CInt::CInt(std::string &s) : CVar() {
    this->name = s;
    this->lineToReference = 0;
    this->value = 0;
}

CInt::CInt(std::string name, CTxt txtFile, int lineToReference, int value, bool getFromConst) : CVar(name, txtFile, lineToReference) {
    this->setName(name);
    this->setTxtFile(txtFile);
    this->setLineToReference(lineToReference);
    this->setValue(0, false);
    std::cout << this->getTxtFile().getPath() << std::endl;
    std::ifstream inFile(this->getTxtFile().getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed in CInt constructor creation of " << name << "." << std::endl;
        std::cerr << "Error: " << strerror(errno) << std::endl;
        inFile.close();
        return;
        //Hello
    }
    std::cout << "Boingo" << std::endl;
    std::vector<std::string> lineArray;
    std::string line;
    int lineWeAreAt = 0;
    while (getline(inFile, line)) {
        lineWeAreAt++;
        lineArray.push_back(line);
        std::cout << "alijfkdnld" << std::endl;
    }
    inFile.close();
    while (lineToReference >= lineArray.size()) {
        std::cerr << "Error: lineToReference is out of range." << std::endl << "Add lines? Y/N" << std::endl;
        std::string userInput;
        std::cin >> userInput;
        bool goOn = false;
        do {
            if (userInput == "Y" || userInput == "y") {
                std::cout << "Gotten here!" << std::endl;
                std::ofstream outFile;
                outFile.open(this->getTxtFile().getPath());
                std::cout << "Gotten here, too!" << std::endl;
                if (outFile.fail()) {
                    std::cerr << "Out Thingy Failed" << std::endl;
                    std::cerr << "Error: " << strerror(errno) << std::endl;
                }
                std::cout << "And here!" << std::endl;
                for (int i = 0; i <= this->getLineToReference(); i++) {
                    outFile << std::endl;
                    std::cout << "Here, as well!" << std::endl;
                }
                std::cout << "Huh?" << std::endl;
                outFile.close();
                goOn = true;
            } else if (userInput == "N" || userInput == "n") {
                int newLineToReference;
                std::cout << "What should the new line to reference be? The maximum is " << lineArray.size() - 1 << "." << std::endl;
                std::cin >> newLineToReference;
                this->setLineToReference(newLineToReference);
                return;
            }
            lineWeAreAt = 0;
            inFile.open(this->getTxtFile().getPath());
            inFile.seekg(0, std::ios::beg);
            lineArray.clear();
            while (getline(inFile, line)) {
                lineArray.push_back(line);
                lineWeAreAt++;
            }
            std::cout << "goOn = " << goOn << std::endl;
            std::cout << "lineArray's size is " << lineArray.size() << std::endl;
            inFile.close();
        } while (!goOn);
        lineArray.clear();
        while (getline(inFile, line)) {
            lineArray.push_back(line);
            lineWeAreAt++;
        }
    }
    inFile.open(this->getTxtFile().getPath());
    std::cout << "Bongo" << std::endl;
    lineWeAreAt = 0;
    inFile.seekg(0, std::ios::beg);
    lineArray.clear();
    while (getline(inFile, line)) {
        lineArray.push_back(line);
        lineWeAreAt++;
    }
    std::cout << "hor" << std::endl;
    inFile.close();

    std::cout << "106" << std::endl;
    if (getFromConst) {
        if (!lineArray.at(this->getLineToReference()).empty()) {
            std::cout << "Hooray?" << std::endl;
            this->setValue(stoi(lineArray.at(getLineToReference())));
            std::cout << "Hooray." << std::endl;
        } else {
            std::cout << "Hooray2?" << std::endl;
            this->setValue(0);
            std::cout << "Hooray2." << std::endl;
        }
    } else {
        std::cout << "Hooray3?" << std::endl;
        std::ofstream outFile;
        outFile.open(this->getTxtFile().getPath());
        if (outFile.fail()) {
            std::cerr << "Out Thingy Failed" << std::endl;
            std::cerr << "Error: " << strerror(errno) << std::endl;
        }
        std::cout << "Horango" << std::endl;
        lineArray[lineToReference] = std::to_string(value);

        for (int i = 0; i < lineArray.size(); i++) {
            outFile << lineArray.at(i);
        }
        outFile.close();
    }
    std::cout << "Bango" << std::endl;
}

CInt::CInt(CInt &ci) : CVar(ci), value(ci.value) {
    this->setName(ci.getName());
    this->setTxtFile(ci.getTxtFile());
    this->lineToReference = ci.getLineToReference();
    this->setValue(ci.getValue());
}

CInt::~CInt() {
    std::cout << "CInt destroyed." << std::endl;
}

void CInt::updateValue() {
    std::cout << "updateValue is trying to access " << this->getTxtFile().getPath() << std::endl;
    std::ifstream inFile(this->getTxtFile().getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed in CInt::updateValue function of " << this->getName() << "." << std::endl;
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return;
        //Hello
    }
    std::vector<std::string> lineArray;
    std::string line;
    int lineWeAreAt = 0;
    while (getline(inFile, line)) {
        lineWeAreAt++;
        lineArray.push_back(line);
        std::cout << "alijfkdnld" << std::endl;
    }
    inFile.close();
    while (this->getLineToReference() >= lineArray.size()) {
        std::cerr << "Error: lineToReference is out of range." << std::endl << "Add lines? Y/N" << std::endl;
        std::string userInput;
        std::cin >> userInput;
        bool goOn = false;
        do {
            if (userInput == "Y" || userInput == "y") {
                std::cout << "Gotten here!" << std::endl;
                std::ofstream outFile;
                outFile.open(this->getTxtFile().getPath());
                std::cout << "Gotten here, too!" << std::endl;
                if (outFile.fail()) {
                    std::cerr << "Out Thingy Failed" << std::endl;
                    std::cerr << "Error: " << strerror(errno) << std::endl;
                }
                std::cout << "And here!" << std::endl;
                for (int i = 0; i <= this->getLineToReference(); i++) {
                    outFile << std::endl;
                    std::cout << "Here, as well!" << std::endl;
                }
                std::cout << "Huh?" << std::endl;
                outFile.close();
                goOn = true;
            } else if (userInput == "N" || userInput == "n") {
                int newLineToReference;
                std::cout << "What should the new line to reference be? The maximum is " << lineArray.size() - 1 << "."
                          << std::endl;
                std::cin >> newLineToReference;
                this->setLineToReference(newLineToReference);
                return;
            }
            lineWeAreAt = 0;
            inFile.open(this->getTxtFile().getPath());
            inFile.seekg(0, std::ios::beg);
            lineArray.clear();
            while (getline(inFile, line)) {
                lineArray.push_back(line);
                lineWeAreAt++;
            }
            std::cout << "goOn = " << goOn << std::endl;
            std::cout << "lineArray's size is " << lineArray.size() << std::endl;
            inFile.close();
        } while (!goOn);
        lineArray.clear();
        while (getline(inFile, line)) {
            lineArray.push_back(line);
            lineWeAreAt++;
        }
    }
}


void CInt::downloadValue() {

}

void CInt::uploadValue() {

}






void CInt::setValue(int n, bool updateValue) {
    this->value = n;
    std::ifstream inFile;
    inFile.open(this->getTxtFile().getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed in CInt constructor creation of " << name << "." << std::endl;
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return;
    }
    std::vector<std::string> lineArray;
    std::string line;
    while(getline(inFile, line)) {
        lineArray.push_back(line);
    }
    lineArray.at(this->getLineToReference()) = std::to_string(n);
    inFile.close();
    std::ofstream outFile;
    outFile.open(this->getTxtFile().getPath());
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
        std::cerr << "Error: " << strerror(errno) << std::endl;
    }
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray.at(i);
    }
    outFile.close();
}

int CInt::getValue(bool updateValue) {
    if (updateValue) {
        this->updateValue();
    }
    return this->value;
}

void CInt::setLineToReference(int line) {
    int cIntValue = this->getValue();
    CVar::setLineToReference(line);
    this->setValue(cIntValue);
}
