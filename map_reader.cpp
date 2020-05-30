#include "map_reader.h"
#include "resource.h"
#include <string>

MapReader::MapReader(std::ifstream &mapFile, ResBlockingQueue &aTriQueue,
                ResBlockingQueue &aMadQueue, ResBlockingQueue &aCarHieQueue) :
                mapFile(mapFile), triQueue(aTriQueue),
                madQueue(aMadQueue), carHieQueue(aCarHieQueue) {}

void MapReader::run() {
    std::string line;
    while (std::getline(this->mapFile, line)) {
        for (std::size_t i = 0; i < line.length(); i++) {
            switch (line[i]) {
            case 'T':
                this->triQueue.push(Resource(WHEAT));
                break;
            
            case 'M':
                this->madQueue.push(Resource(WOOD));
                break;

            case 'C':
                this->carHieQueue.push(Resource(COAL));
                break;

            case 'H':
                this->carHieQueue.push(Resource(IRON));
                break;
            }
        }
    }
}
