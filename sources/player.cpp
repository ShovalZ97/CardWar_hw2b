#include "player.hpp"

namespace ariel {

    //Constructor
    Player::Player(std::string name):name(name)
    {
        this->name = name;
        this->inPlay=false;
        this->cardsTaken=0;
    }

}