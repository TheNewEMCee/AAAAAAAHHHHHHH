#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>
#include <unistd.h>
#include "CFile.h"
#include "CTxt.h"

CTxt::CTxt() : CFile() {

}

CTxt::CTxt(const std::string &name, const std::string &path) : CFile(name, path) {
    this->setName(name);
    this->setPath(path);
}
CTxt::~CTxt() {
    //std::cout << "CTxt " << this->getName() << " at " << this->getPath() << " destroyed." << std::endl;
}
void CTxt::printFile(int start, int finish, int width, bool isBeautified) {
    /*
    if (start <= 0 || finish > this->getNumLines()) {
        std::string isBeautifiedStr;
        if (isBeautified) {
            isBeautifiedStr = "true";
        } else if (!isBeautified) {
            isBeautifiedStr = "false";
        } else {
            isBeautifiedStr = "???";
        }
        std::cout << "While calling the function printFile(start = " << start << ", finish = " << finish << ", width = " << width << ", isBeautified = " << isBeautifiedStr << "), " << this->getName() << "'s start or finish is out of bounds." << std::endl;

    }
    std::ifstream inFile;
    width -= 7;
    inFile.open(this->getPath());
    if (isBeautified) {
        int lineCount = 1;
        std::string line;
        std::vector<std::pair<int, std::string>> lineArray;
        while (getline(inFile, line)) {
            lineCount++;
            if (start <= lineCount <= finish) {
                lineArray.push_back(std::make_pair(lineCount, line));
            }
        }
        std::cout << "╭────┬";
        for (int i = 0; i < width; i++) {
            std::cout << "─";
        }
        std::cout << "╮" << std::endl;
        std::cout << "│NAME│" << this->getName();
        for (int i = 0; i < width - this->getName().size(); i++) {
            std::cout << " ";
        }
        std::cout << "│" << std::endl;
        std::cout << "├────┼";
        for (int i = 0; i < width; i++) {
            std::cout << "─";
        }

        std::cout << std::endl << "│NAME│" << this->getName();
        for (int i = 0; i < width - this->getName().size(); i++) {
            std::cout << " ";
        }
        for (int i = start; i <= finish; i++) {
            if (0 < i < )

            for (int j = 1; j < 10; j++) {
                std::cout << "│" << "000" << lineArray.at(j - 1).first << "│";
                bool leftoverLines = true;
                bool firstLine = true;
                int leftoverCharacters = 0;
                int charCount = lineArray.at(j - 1).second.size();
                if (charCount <= width) {
                    std::cout << lineArray.at(j - 1).second;
                } else {
                    while (charCount > width) {
                        if (firstLine) {
                            std::cout << lineArray.at(j - 1).second.substr(0, width) << "│" << std::endl;
                            firstLine = false;
                        } else {
                            std::cout << "│   │" << lineArray.at(j - 1).second.substr(0, width);
                        }
                        charCount -= width;
                    };
                    if (charCount <= width) {
                        std::cout << "│   │";
                    }
                }
            }
        }

    }
     */

}
void CTxt::updateNumLines() {}
int CTxt::getNumLines() {
    return 1000;
}
bool CTxt::isValidPath() {
    std::ifstream inFile;
    inFile.open(this->getPath());
    if (inFile.fail()) {
        std::cerr << this->getName() << " has an invalid path." << std::endl;
        std::cerr << "Error: " << strerror(errno) << std::endl;
        inFile.close();
        return false;
    } else {
        std::cout << this->getName() << " has a valid path." << std::endl;
        inFile.close();
        return true;
    }
}