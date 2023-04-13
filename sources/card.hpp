#pragma once

#include <iostream>
#include <string>

using namespace std;

enum NumCard
{
    Two= 1,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};
enum ShapeCard
{
    Diamonds = 1,
    Clubs,
    Spades,
    Hearts
    
};

namespace ariel
{
     class Card
    {
        private:
            NumCard num;
            ShapeCard shape;
        public:
            Card(NumCard num = Ace, ShapeCard shape = Diamonds);
            //Get the num of the card.
            NumCard getNumCard() 
            {
                return this->num;
            }
            //Get the shape of the card
            ShapeCard getShapeCard()  
            {
                return this->shape;
            }
            //Compare two cards if they are equally.
            bool compareCard(Card other) 
            {
                return this->num == other.num;
            }
            string toString();
    };
}