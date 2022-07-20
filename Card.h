#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
    protected:

        std::string cardname;
        int cardvalue;
        bool faceUp = false;

    public:

        Card(std::string, int);
        bool isFaceUp();
        int getValue();
        void flip();
        std::string getName();

        ~Card();


};


#endif