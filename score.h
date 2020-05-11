#ifndef __SCORE_H__
#define __SCORE_H__

#include "inventory.h"

class Score {
    private:
        int finalScore;
        Inventory &inventory;

    public:
        Score(Inventory &anInventory);
        void printScore();
};

#endif
