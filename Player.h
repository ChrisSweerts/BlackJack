#ifndef PLAYER_H
#define PLAYER_H
#include "GenericPlayer.h"
#include "Hand.h"
#include "Deck.h"

class Player : public GenericPlayer
{
    private:

        
    public:

    void win();
    void lose();
    void push();

    
};

#endif