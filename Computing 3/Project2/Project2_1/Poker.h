#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

class Card
{
private:
    int face,suit;
public:
        static string faces[],suits[];
    Card(int inpFace,int inpSuit)
    {
        face = inpFace;
        suit = inpSuit;

    }
    string toString()
    {
        string temp;
        temp = faces[face] + " of " + suits[suit];
        return temp;
    }

};

class DeckOfCards
{
private:
    vector<Card> deck;
    int currentCard;
public:
    DeckOfCards(); //Default initializer that initializes all the cards in the deck
    void shuffle(); //shuffle the deck
    Card dealCard(); //Returns the next card object from the deck and removes it from the deck
    bool moreCard(); //Returns a value indicating whether there are more Cards to deal

};

#endif // POKER_H_INCLUDED
