#include "score.h"
#include <iostream>

Score::Score() :  
    score(0) {}

void Score::addToScore(int points) {
    std::unique_lock<std::mutex> lk(mux);
    this->score += points;
}

void Score::printScore() {
    std::cout << "Puntos de Beneficio acumulados: " << this->score << std::endl;
}
