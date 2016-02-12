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
    int res;
    DeckOfCards deck;
    Hand dealer,player;
//    int i = 1;
//    int i = 1;
//    while(deck.moreCard() == 1)
//    {
//        Card temp = deck.dealCard();
//        cout << i << ". " << temp.toString() << endl;
//        i++;
//    }
    cout << "Player: " << endl;
    player.dealHand(&deck);
    player.faceSort();
    player.printHand();
    //player.calcHandValue();
    cout << endl << endl;
    player.replaceCardsPlayer(&deck);
    cout << endl;
    player.printHand();
    player.calcHandValue();
    cout << endl << "Dealer: " << endl;
    dealer.dealHand(&deck);
    //dealer.calcHandValue();
    dealer.replaceCardsDealer(player,&deck);
    dealer.calcHandValue();
    dealer.printHand();
    res = dealer.greaterHand(dealer,player);
    if(res == 1)
    {
        cout << "Dealer Wins!" << endl;
    }
    else
    {
        cout << "Player Wins!" << endl;
    }
}
