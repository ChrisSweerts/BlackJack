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
#include <bits/stdc++.h>
#include <vector>
#include <iostream>     
#include <algorithm>    
#include <ctime>        
#include <cstdlib>

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





void Game :: play(){
    std::string again = "";
    //the whole thing is in a do while loop just to check if the user would like
    //to play the game again and if they do it will completeley repopulate the deck.
    do{
    //Initializing my variables that I will be using
    int players;
    std::string playernames = "";
    Deck decky;
    House housey;
    //Getting the amount of players playing in the game.
    do{
        std::cout << "How many players do you want in this hand? (1-7): ";
        std::cin >> players;
    } while ((players > 7) || (players < 1));
    
    std::vector<Player> playername(7);

    for(int x = 0; x < players; x++){
        std::cout << "Enter player " << x+1 << "'s name: ";
        std::cin >> playernames;
        playername[x].setPlayerName(playernames);
    }
    decky.populate();
    decky.shuffle();
    for(int l = 0; l < 2; l++){
        for(int z = 0; z < players; z++){
            decky.deal(playername[z]);
        }
        decky.deal(housey);
    }

    housey.flipFirstCard();

    for(int p = 0; p < players; p++){
        std::cout << playername[p].getPlayerName() << ": ";
        playername[p].printCards(); 
        std::cout << " " << playername[p].getTotal() << std::endl;
    }
    std::cout << "House: ";
    housey.printCards();
    std::cout << " " << housey.getTotal() << std::endl;
    std::vector<int> playersGone;
    int gone = 0;
    //This large for loop simply goes through all of the players that are playing and checks
    // if they have 21 already and if they dont, it will ask them if they want to hit another card
    for(int o = 0; o < players; o++){
        if(playername[o].getTotal() == 21){
            std::cout << playername[o].getPlayerName() << " got a BlackJack!" << std::endl;
        }else{
        while(playername[o].isHitting() == true){
            decky.deal(playername[o]);
            std::cout << playername[o].getPlayerName() << ": ";
            playername[o].printCards(); 
            std::cout << " " << playername[o].getTotal() << std::endl;
            if(playername[o].getTotal() == 21){
                break;
            }
            if(playername[o].isBusted() == true){
                playername[o].bust();
                playersGone.push_back(o);
                gone++;
                break;
            }
        }
        }
    }
    int pleas = gone;
    for(int n = 0; n < gone; n++){
        playername.erase(playername.begin() + playersGone[pleas - 1]);
        players--;
        pleas--;
    }
    //I flip back the first card so that now I can continue the game just as if the house were a
    // normal player and i do not have to do anything different for the getTotal function.
    housey.flipFirstCard();

    while(housey.getTotal() <= 16){
        std::cout << "House: ";
        housey.printCards();
        std::cout << " " << housey.getTotal() << std::endl;
        decky.deal(housey);
    }
    std::cout << "House: ";
    housey.printCards();
    std::cout << " " << housey.getTotal() << std::endl;
    if(housey.getTotal() > 21){
        for(int h = 0; h < players; h++){
            playername[h].win();
        }
    }else{
        for(int k = 0; k < players; k++){
            if(playername[k].getTotal() > housey.getTotal()){
                playername[k].win();
            }
            else if (playername[k].getTotal() < housey.getTotal()){
                playername[k].lose();
            }else{
                playername[k].push();
            }
        }
    }
    std::cout << "Would you like to play this game again? (y or n): ";
    std::cin>>again;
    }while(again == "y" || again == "Y");

}