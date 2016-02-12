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
    int getFace()
    {
        return face;
    }
    int getSuit()
    {
        return suit;
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
//private:
//    vector<Card> hand;
//    vector<int> junkCards;
//    int handValue,highCard,highCards[3],numP,proximity[8],towardsFlush[5],towardsStraight[2]; //proximity is closeness to a hand
public:
    vector<Card> hand;
    vector<int> junkCards;
    int handValue,highCard,highCards[3],numP,proximity[8],towardsFlush[5],towardsStraight[2]; //proximity is closeness to a hand

    Hand(); //Deal five cards to hand
    //all of these functions need to set handValue, highest card,proximity and junk cards
    void hasFlush(); //check for a flush
    void hasStraight(); //check for a straight
    void hasFourOfAKind(); // check for four of a kind
    void hasThreeOfAKind(); //check for three of a kind
    void hasTwoPair(); //check for two pair
    void hasPairs(); //check for pair
    void calcHandValue(); //calculate the hand value(call all the other functions)
    void suitSort();
    void faceSort();
    void printHand();
    void dealHand(DeckOfCards * arg);
    int greaterHand(Hand dealer,Hand player);
    void replaceCardsPlayer(DeckOfCards * deck); // replace num amount of cards
    void replaceCardsDealer(Hand player,DeckOfCards * deck);
    void countSuits(int * arr);
    void countStraights(int *arr);


};

#endif // POKER_H_INCLUDED
