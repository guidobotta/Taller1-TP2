#include "map_reader.h"
#include "resource.h"
#include <string>

MapReader::MapReader(std::ifstream &mapFile, ResBlockingQueue &aWheatQueue,
                ResBlockingQueue &aWoodQueue, ResBlockingQueue &aCoalIronQueue)
                : mapFile(mapFile), wheatQueue(aWheatQueue),
                  woodQueue(aWoodQueue), coalIronQueue(aCoalIronQueue) {}

void MapReader::run() {
    std::string line;
    while (std::getline(this->mapFile, line)) {
        for (std::size_t i = 0; i < line.length(); i++) {
            switch (line[i]) {
            case 'T':
                this->wheatQueue.push(Resource(WHEAT));
                break;
            
            case 'M':
                this->woodQueue.push(Resource(WOOD));
                break;

            case 'C':
                this->coalIronQueue.push(Resource(COAL));
                break;

            case 'H':
                this->coalIronQueue.push(Resource(IRON));
                break;
            }
        }
    }
}
