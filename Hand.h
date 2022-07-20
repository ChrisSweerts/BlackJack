#ifndef HAND_H
#define HAND_H
#include <vector>
#include <string>
#include "Card.h"

class Hand
{
    protected:
        std::vector<Card> cardshand;
    public:

    void add(Card& card);
    void clear();
    int getTotal();
    void printCards();


};

#endif