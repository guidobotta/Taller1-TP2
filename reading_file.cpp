#include "reading_file.h"

ReadingFile::ReadingFile(const std::string &path) {
    this->file.open(path, std::ios::in);
}

ReadingFile::~ReadingFile() {
    this->file.close();
}

void ReadingFile::getLine(std::string &str) {
    str = "";

    if (this->file.is_open()) {
        getline(this->file, str);
    }
}

void ReadingFile::getCompleteFile(std::string &str) {
    std::string filestr;
    str = "";

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, filestr);
            str.append(filestr);
        }
    }
}