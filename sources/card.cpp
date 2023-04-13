#include <iostream>
#include <string>
using namespace std;

#include "card.hpp"

namespace ariel {
    Card::Card(NumCard num, ShapeCard shape)
    { 
        this->num=num;
        this->shape=shape;
    }
    string Card::toString() 
    {
        string num2, shape2;
        NumCard num = this->getNumCard();
        ShapeCard shape = this->getShapeCard();

        switch (num)
        {
            case Ace:
                num2 = "Ace";
                break;
            case Jack:
                num2 = "Jack";
                break;
            case Queen:
                num2 = "Queen";
                break;
            case King:
                num2 = "King";
                break;
            default:
                num2 = to_string((int)num);
                break;
        }
        switch (shape)
        {
            case Clubs:
                shape2 = "Clubs";
                break;
            case Diamonds:
                shape2 = "Diamonds";
                break;
            case Hearts:
                shape2 = "Hearts";
                break;
            case Spades:
                shape2 = "Spades";
                break;
        }
        return ( num2 + " of " +shape2+".");
    }
}