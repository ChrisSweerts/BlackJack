#include "Card.h"
#include <string>

// Constructor for the cards
Card :: Card(std::string cardnamey, int cardvaluey)
    : cardname{cardnamey}, cardvalue{cardvaluey}, faceUp{true}{};

bool Card :: isFaceUp(){
    return faceUp;
}

void Card :: flip(){
    faceUp = !faceUp;
}

int Card :: getValue(){
    return cardvalue;
}

std::string Card:: getName(){
    return cardname;
}
//Destructor for the Card constructor
Card :: ~Card(){

}