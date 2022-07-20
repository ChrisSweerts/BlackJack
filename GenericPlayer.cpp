#include "GenericPlayer.h"
#include <iostream>
#include <string>

bool GenericPlayer :: isHitting(){
    std::string yesno = " ";
    std::cout << actualName << ", would you like to get another card (y or n): ";
    std::cin >> yesno;

    if(yesno == "y" || yesno == "Y"){
        return true;
    } else{
        return false;
    }
    
}

bool GenericPlayer :: isBusted(){
    int t = 0;
    for(auto& elem : cardshand){ 
        if (elem.isFaceUp() == true){
            t += elem.getValue();
        }
        
    }

    if(t > 21){
        for(auto& reez : cardshand){
            if(reez.getValue() == 11){
                // subtracts 10 if it finds out that there is an ace in the players hand.
                t -= 10;
                if(t <= 21){
                    return false;
                }
            }
        }
    }

    if(t > 21){
        return true;
    } else{
        return false;
    }

}

void GenericPlayer :: bust(){
    std::cout << "Your hand is a bust! " << std::endl;
}

void GenericPlayer :: setPlayerName(std::string namer){
    actualName = namer;
}

std::string GenericPlayer :: getPlayerName(){
    return actualName;
}
