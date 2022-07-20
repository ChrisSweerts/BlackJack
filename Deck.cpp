#include "Deck.h"
#include "GenericPlayer.h"
#include "Card.h"
#include <vector>
#include <iostream>     
#include <algorithm>    
#include <ctime>        
#include <cstdlib>

void Deck :: populate(){
    Card dA("Ad", 11), d2("2d", 2), d3("3d", 3), d4("4d", 4), d5("5d", 5), d6("6d", 6), d7("7d", 7), d8("8d", 8), d9("9d", 9), d10("10d", 10), dJ("Jd", 10), dQ("Qd", 10), dK("Kd", 10), hA("Ah", 11), h2("2h", 2), h3("3h", 3), h4("4h", 4), h5("5h", 5), h6("6h", 6), h7("7h", 7), h8("8h", 8), h9("9h", 9), h10("10h", 10), hJ("Jh", 10), hQ("Qh", 10), hK("Kh", 10), sA("As", 11), s2("2s", 2), s3("3s", 3), s4("4s", 4), s5("5s", 5), s6("6s", 6), s7("7s", 7), s8("8s", 8), s9("9s", 9), s10("10s", 10), sJ("Js", 10), sQ("Qs", 10), sK("Ks", 10), cA("Ac", 11), c2("2c", 2), c3("3c", 3), c4("4c", 4), c5("5c", 5), c6("6c", 6), c7("7c", 7), c8("8c", 8), c9("9c", 9), c10("10c", 10), cJ("Jc", 10), cQ("Qc", 10), cK("Kc", 10);

    cardshand = {dA, d2, d3, d4, d5, d6, d7, d8, d9, d10, dJ, dQ, dK, hA, h2, h3, h4, h5, h6, h7, h8, h9, h10, hJ, hQ, hK, sA, s2, s3, s4, s5, s6, s7, s8, s9, s10, sJ, sQ, sK, cA, c2, c3, c4, c5, c6, c7, c8, c9, c10, cJ, cQ, cK};

}

void Deck :: shuffle(){
    std::srand(std::time(NULL));
    std::random_shuffle(cardshand.begin(), cardshand.end());


}

void Deck :: deal(Hand& hand){
    hand.add(cardshand[0]);
    cardshand.erase(cardshand.begin());
}

void Deck :: additionalCards(GenericPlayer& gp){
    if (gp.isHitting() == true){
        gp.add(cardshand[0]);
    }
}
