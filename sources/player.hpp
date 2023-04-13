#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            vector<Card> cardsHand;
            bool inPlay;
            int cardsTaken;

        public:
            //Constructors
            Player(string name);
            //Const means that we didnt want that someone change the details , just to see
            int stacksize() const
            { 
                return (int)this->cardsHand.size(); 
            } 
            int cardesTaken() const
            { 
                return this->cardsTaken; 
            }
            //& - this means that we want use in this card and not copy
            //The cards in our hand
            void addCardToHand(Card& card) 
            { 
                this->cardsHand.push_back(card);
            }
            //The cards that win
            void addCardTaken() 
            { 
                this->cardsTaken++; 
            }
            const Card& getCard()
            {
                return this->cardsHand.back();
            }
            void removeCard() 
            { 
                this->cardsHand.pop_back();
            }
            //If in play
            bool InPlaying() const 
            { 
                return this->inPlay; 
            }
            void setPlay(bool ifPlay) 
            {
                this->inPlay = ifPlay;
            }
            string getName()
            { 
                return this->name; 
            }
            
    };
}