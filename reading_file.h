#ifndef __READING_FILE_H__
#define __READING_FILE_H__

#include <fstream>

class ReadingFile {
    private:
        std::ifstream file;

    public:
        ReadingFile(const std::string path);
        ~ReadingFile();
        
};

#endif
