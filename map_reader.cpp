#include "map_reader.h"
#include "resource.h"
#include <string>

MapReader::MapReader(FileReader &aFileReader, ResBlockingQueue &aTriQueue,
                ResBlockingQueue &aMadQueue, ResBlockingQueue &aCarHieQueue) :
                fileReader(aFileReader), triQueue(aTriQueue),
                madQueue(aMadQueue), carHieQueue(aCarHieQueue) {}

void MapReader::operator()() {
    std::string line;
    while (!this->fileReader.eof()) {
        this->fileReader.getLine(line);

        for (int i = 0; i < line.length(); i++) {
            switch (line[i]) {
            case 'T':
                this->triQueue.push(new Resource(TRIGO)); //NECESITO HACERLO ASI O PUEDO NO HACER EL NEW??
                break;
            
            case 'M':
                this->madQueue.push(new Resource(MADERA));
                break;

            case 'C':
                this->carHieQueue.push(new Resource(CARBON));
                break;

            case 'H':
                this->carHieQueue.push(new Resource(HIERRO));
                break;
            }
        }
    }
}
