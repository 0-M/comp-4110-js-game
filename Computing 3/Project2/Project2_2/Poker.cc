#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Poker.h"
#include <time.h>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::swap;


//DeckOfCards function definitions

DeckOfCards::DeckOfCards() //Default initializer that initializes all the cards in the deck
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            Card Temp(j,i);
            deck.push_back(Temp);
        }
    }
    for(int i = 0; i < 10; i++)
    {
        shuffle();
    }
}
void DeckOfCards::shuffle() //shuffle the deck
{
    srand (time(NULL));
    for(int i = 0; i < 52; i++)
    {
        swap(deck[i],deck[rand() % 51]);
    }
}
Card DeckOfCards::dealCard() //Returns the next card object from the deck and removes it from the deck
{
    Card temp = deck.back();
    deck.pop_back();
    return temp;
}
bool DeckOfCards::moreCard() //Returns a value indicating whether there are more Cards to deal
{
    if(deck.size() != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Hand class

Hand(); //Deal five cards to hand

    //all of these functions need to set handValue, highest card,proximity and junk cards
   void hasFlush(); //check for a flush
   void hasStraight(); //check for a straight
   void hasFourOfAKind(); // check for four of a kind
   void hasThreeOfAKind(); //check for three of a kind
   void hasTwoPair(); //check for two pair
   void hasPair(); //check for pair
   void calcHandValue(); //calculate the hand value(call all the other functions)
   void replaceCards(int num); // replace num amount of card



