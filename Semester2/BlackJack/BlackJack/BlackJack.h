#include "Deck.h"

typedef struct Dealer
{
	Hand hand;
}Dealer, *DealerPtr;

typedef struct Player
{
	int cash;
	Hand hand;
}Player, *PlayerPtr;

/*****Functions for Blackjack*/

/*Plays one round of blackjack*/
int playBlackjack(DeckPtr deck, Dealer dealer, Player player);

/*checks the given hand for b  blackjack, returns 1 if the hand has blackjack and 0 if it doesn't*/
int checkForBlackjack(Hand hand);

/*****Functions for setting up cards*/
DeckPtr makeDeck(int numberOfDecks);
