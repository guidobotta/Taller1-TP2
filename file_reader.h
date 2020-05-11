#ifndef __READING_FILE_H__
#define __READING_FILE_H__

#include <fstream>
#include <string>

class FileReader {
    private:
        std::ifstream file;

    public:
        FileReader(const std::string &path);
        ~FileReader();
        void getLine(std::string &str);
        void getCompleteFile(std::string &str);
        bool eof();
};

#endif