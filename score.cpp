#include "score.h"
#include <iostream>

Score::Score(Inventory &anInventory) :  
    finalScore(0),
    inventory(anInventory) {}

void Score::addToScore(int points) {
    this->finalScore += points;
}

void Score::printScore() { 
    std::cout << "Recursos restantes:" << std::endl;
    std::cout << "-  Trigo: " << this->inventory.getTrigoAmount() 
        << std::endl;
    std::cout << "-  Madera: " << this->inventory.getMaderaAmount() 
        << std::endl;
    std::cout << "-  Carbon: " << this->inventory.getCarbonAmount() 
        << std::endl;
    std::cout << "-  Hierro: " << this->inventory.getHierroAmount() 
        << std::endl;
    std::cout << std::endl;
    std::cout << "Puntos de Beneficio acumulados: " << this->finalScore 
        << std::endl;
}