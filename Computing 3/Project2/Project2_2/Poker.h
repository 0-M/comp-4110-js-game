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

class Hand
{
private:
    vector<int> junkCards;
    vector<Card> hand;
    int handValue,highestCard,proximity[6]; //proximity is closeness to a hand
public:
    Hand(); //Deal five cards to hand
    //all of these functions need to set handValue, highest card,proximity and junk cards
   void hasFlush(); //check for a flush
   void hasStraight(); //check for a straight
   void hasFourOfAKind(); // check for four of a kind
   void hasThreeOfAKind(); //check for three of a kind
   void hasTwoPair(); //check for two pair
   void hasPair(); //check for pair
   void calcHandValue(); //calculate the hand value(call all the other functions)
   void replaceCards(int num); // replace num amount of cards


};

#endif // POKER_H_INCLUDED
