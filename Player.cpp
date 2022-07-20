#include "Player.h"
#include "Deck.h"
#include <iostream>

void Player :: win(){
    std::cout << "Player: " << actualName << " wins!\n";
}

void Player :: lose(){
    std::cout << "Player: " << actualName << " loses!\n";
}

void Player :: push(){
    std::cout << "Player: " << actualName << " pushes!\n";
    
}