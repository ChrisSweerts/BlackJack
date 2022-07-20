#include "Hand.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <string>

void Hand :: add(Card& card){
    cardshand.push_back(card);
}

void Hand :: clear(){
    cardshand.clear();
}

int Hand :: getTotal(){
    int t = 0;
    for(auto& elem : cardshand){
        if (elem.isFaceUp() == true){
            t += elem.getValue();
        }
        
    }
    if(t > 21){
        for(auto& jeez : cardshand){
            if(jeez.getValue() == 11){
                t -= 10;
                if(t <= 21){
                    return t;
                }
            }
        }
    }
    return t;

}

void Hand :: printCards(){
    for(auto& elem : cardshand){
        if (elem.isFaceUp() == true){
            std::cout << elem.getName() << " ";
        }else {
            std::cout << "?? ";
        }
        
    }
}
