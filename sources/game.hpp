#pragma once

#include <vector>
#include "card.hpp"
#include "player.hpp"

namespace ariel
{
    class Game
    {
        private:
            Player& player1;
            Player& player2; 
            string lastTurn,printAll,winner; 
            int player1Winner,player2Winner,draws,numTurn;
        public:
            //Constuctors
            Game(Player& plr1, Player& plr2);
            //Functions
            void playTurn();
            void printLastTurn() const;
            void playAll();
            void printWiner() const;
            void printLog() const;
            void printStats() const;
    };
}