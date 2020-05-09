#include "reading_file.h"

ReadingFile::ReadingFile(const std::string path) {
    this->file.open(path, std::ios::in);
}

ReadingFile::~ReadingFile() {
    this->file.close();
}
