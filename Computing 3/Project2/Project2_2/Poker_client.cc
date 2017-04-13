#include <iostream>
#include <cstdlib>
#include <string>
#include "Poker.h"

using  std::cout;
using  std::cin;
using  std::endl;
using  std::string;

string Card::faces[] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
string Card::suits[] = {"Spades","Clubs","Hearts","Diamonds"};

int main(int argc, char* argv[]) // For suits 0 = Spades, 1 = Clubs, 2 = Hearts, 3 = Diamonds
{
    DeckOfCards deck;
    int i = 1;
    while(deck.moreCard() == 1)
    {
        Card temp = deck.dealCard();
        cout << i << ". " << temp.toString() << endl;
        i++;
    }

}
