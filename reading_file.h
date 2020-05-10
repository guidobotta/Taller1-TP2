#ifndef __READING_FILE_H__
#define __READING_FILE_H__

#include <fstream>
#include <string>

class ReadingFile {
    private:
        std::ifstream file;

    public:
        ReadingFile(const std::string &path);
        ~ReadingFile();
        void getLine(std::string &str);
        void getCompleteFile(std::string &str);
};

#endif
