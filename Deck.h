#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
        
    public:


    void populate();
    void shuffle();
    void deal(Hand& hand);
    void additionalCards(GenericPlayer& gp);


};

#endif