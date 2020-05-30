#ifndef __SCORE_H__
#define __SCORE_H__

#include "inventory.h"
#include <mutex>

class Score {
    private:
        int score;
        std::mutex mux;

    public:
        Score();
        void addToScore(int points);
        void printScore();
};

#endif
