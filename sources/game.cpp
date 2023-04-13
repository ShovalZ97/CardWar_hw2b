#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player &ply1, Player &ply2) : player1(ply1), player2(ply2)
    {
        this->lastTurn = "";
        this->winner = "";
        this->numTurn = 0;
        this->player1Winner = 0;
        this->player2Winner = 0;
        this->printAll = "";
        if (ply1.InPlaying())
            throw invalid_argument("player 1 is in another game");
        if (ply1.InPlaying())
            throw invalid_argument("player 2 is in another game");
        vector<Card> cardsGame;
        for (int i = 1; i < 14; ++i)
        {
            cardsGame.push_back(Card((NumCard)i, Hearts));
        }
        for (int i = 1; i < 14; ++i)
        {
            cardsGame.push_back(Card((NumCard)i, Spades));
        }
        for (int i = 1; i < 14; ++i)
        {
            cardsGame.push_back(Card((NumCard)i, Clubs));
        }
        for (int i = 1; i < 14; ++i)
        {
            cardsGame.push_back(Card((NumCard)i, Diamonds));
        }
        // Shuffle the cards
        auto rd = std::random_device{};
        auto rng = std::default_random_engine{rd()};
        shuffle(begin(cardsGame), end(cardsGame), rng);
        for (int i = 0; i < 26; i++)
        {
            this->player1.addCardToHand(cardsGame.back());
            cardsGame.pop_back();
        }
        for (int i = 0; i < 26; i++)
        {
            this->player2.addCardToHand(cardsGame.back());
            cardsGame.pop_back();
        }
        // Inside the players to the game
        this->player1.setPlay(true);
        this->player2.setPlay(true);
    }
    void Game::printLastTurn() const
    {
        cout << this << endl;
    }
    void Game::playTurn()
    {
        if (&player1 == &player2)
            throw invalid_argument("cannot inside with the same player");
        if (!player1.InPlaying() || !player2.InPlaying())
        {
            throw invalid_argument("End of the game");
        }
        this->numTurn++;
        if (this->numTurn > 26)
            throw invalid_argument("the maxium of turns is 26");
        Card card1 = player1.getCard();
        Card card2 = player2.getCard();
        player1.removeCard();
        player2.removeCard();
        int cardsToWinner = 2, draws = 0;
        this->lastTurn = "";
        // if there is teko and last card
        while (card1.getNumCard() == card2.getNumCard() && player1.stacksize() > 0 && player2.stacksize() > 0)
        {
            draws++;
            this->lastTurn += "Draw.\n";
            // if there is more 1 card
            if (player1.stacksize() > 1 && player2.stacksize() > 1)
            {
                // the card that upside down
                card1 = player1.getCard();
                card2 = player2.getCard();
                player1.removeCard();
                player2.removeCard();
                cardsToWinner += 2;
            }
            // the card that we see and not upside down
            card1 = player1.getCard();
            card2 = player2.getCard();
            player1.removeCard();
            player2.removeCard();
            cardsToWinner += 2;
        }
        if (card1.getNumCard() < card2.getNumCard())
        {
            // if there is ace and 2 so ace win all without two that wins ace
            if (card1.getNumCard() == 1 && card2.getNumCard() == 13)
            {
                this->lastTurn += player1.getName() + " played " + card1.toString() +
                                  player2.getName() + " played " + card2.toString() + player1.getName() + " Wins " + "\n";
                this->player1Winner++;
                for (int i = cardsToWinner; i > 0; i--)
                {
                    player1.addCardTaken();
                }
            }
            else
            {
                this->lastTurn += player1.getName() + " played " + card1.toString() +
                                  player2.getName() + " played " + card2.toString() + player2.getName() + " Wins " + "\n";
                this->player2Winner++;
                for (int i = cardsToWinner; i > 0; i--)
                {
                    player2.addCardTaken();
                }
            }
        }
        else if (card2.getNumCard() < card1.getNumCard())
        {
            if (card2.getNumCard() == 1 && card1.getNumCard() == 13)
            {
                this->lastTurn += player1.getName() + " played " + card1.toString() +
                                  player2.getName() + " played " + card2.toString() + player1.getName() + " Wins " + "\n";
                this->player2Winner++;
                for (int i = cardsToWinner; i > 0; i--)
                {
                    player2.addCardTaken();
                }
            }
            else
            {
                this->lastTurn += player1.getName() + " played " + card1.toString() +
                                  player2.getName() + " played " + card2.toString() + player1.getName() + " Wins " + "\n";
                this->player1Winner++;
                for (int i = cardsToWinner; i > 0; i--)
                {
                    player1.addCardTaken();
                }
            }
        }
        else
        {
            // if there is teko we want to divide the cards to half
            for (int i = cardsToWinner / 2; i > 0; i--)
            {
                player1.addCardTaken();
                player2.addCardTaken();
            }
        }
        if (!player1.stacksize() || !player2.stacksize())
        {
            player1.setPlay(false);
            player2.setPlay(false);
        }
        if (player1.cardesTaken() > player2.cardesTaken())
            this->winner = player1.getName();
        else
        {
            if (player2.cardesTaken() > player1.cardesTaken())
            {
                this->winner = player2.getName();
            }
        }
        this->draws += (unsigned int)draws;
        this->printAll += this->lastTurn;
    }
    void Game::playAll()
    {
        while (player1.InPlaying() && player2.InPlaying() && this->numTurn < 26)
            playTurn();
    }
    void Game::printWiner() const
    {
        if (player1.InPlaying() || player1.InPlaying())
            return;
        if (player1.cardesTaken() == player2.cardesTaken())
            cout << " Draw." << endl;
        else
            cout << " The winner is: " << this->winner << endl;
    }
    void Game::printLog() const
    {
        cout << printAll << endl;
    }
    void Game::printStats() const
    {
        cout << player1.getName() << endl;
        cout << "Num of cards that win: " << player1.cardesTaken() << endl;
        cout << player2.getName() << endl;
        cout << "Num of cards that win: " << player2.cardesTaken() << endl;
        cout << "Num of the draws: " << this->draws << endl;
        cout << "Num of the turns: " << this->numTurn << endl;
        if (this->winner != "")
            cout << "Winning player: " << this->winner << endl;
        else
            cout << "Not the finall " << endl;
    }
}