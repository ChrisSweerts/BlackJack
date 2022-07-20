#include "Player.h"
#include "House.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>

/** =======================================================================
 * Author: Christopher Sweerts
 * Date:  June 3, 2022
 *
This program is a blackjack game that allows the user(s) to play with 7 people maximum
at a time. The program is a completely working blackjack game that ensures the house
follows all of the blackjack rules (standing on 17 or above). This game of blackjack only
has one deck of cards but the user can play as many times as they would like due to a built in
do while (go again) function
 *
 * Course:   Programming 25                     
 * Teacher:  Ms. Deepeka Dalal
* ========================================================================*/

using namespace std;


int main() 
{
    // creating object blackjack
    Game blackJack;
    // making the object "blackJack" go through the play function which contains the entire blackjack game!
    blackJack.play();

    return 0;
}
