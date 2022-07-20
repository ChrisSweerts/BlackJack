#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include "Hand.h"

class GenericPlayer : public Hand
{
    protected:

    std::string actualName;

    public:

    void setPlayerName(std::string);
    std::string getPlayerName();
    bool isHitting();
    bool isBusted();
    void bust();


};

#endif