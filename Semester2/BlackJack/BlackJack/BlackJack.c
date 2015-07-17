#include <stdio.h>
#include <stdlib.h>
#include "BlackJack.h"

#define MAX_BET 1000

int main(int argc, char *argv[])
{
    DeckPtr deck = makeDeck(2);
    Player player;
    Dealer dealer;
    player.hand.inHand = 0;
    player.cash = 1000;
    dealer.hand.inHand = 0;
    deck = shuffleCards(deck);
    int playAgain;
    playAgain = 0;

    /*Debug functions*/
    //printDeck(deck);
    //printf("\n%d\n", deck->cardsLeft);
    player.cash = playBlackjack(deck, dealer, player);

    printf("Do you want to play another hand? [1]Yes or [2]No: ");
    scanf("%d",&playAgain);
    while(playAgain == 1)
    {
        player.cash = playBlackjack(deck, dealer, player);
        printf("Do you want to play another hand? [1]Yes or [2]No: ");
        scanf("%d",&playAgain);
    }

    empty(deck);
    destroyDeck(deck);

    return 0;
}

DeckPtr makeDeck(int numberOfDecks)
{
    Card newCard;
    DeckPtr deck = initDeck(numberOfDecks);

    int i;
    int j;
    int h;
    int count;
    count = 0;

    for(h = 0; h < numberOfDecks; h++)
    {
        for(j = 3; j < 7; j++)
        {
            for(i = 1; i < 14; i++)
            {
                newCard.value = i;
                newCard.suit = j;
                newCard.faceUp = 1;
                push(deck, newCard);
                count++;
            }
        }
    }
    return deck;
}

int playBlackjack(DeckPtr deck, Dealer dealer, Player player)
{
    int bet;
    int choice;
    int dealerTotal;
    int playerTotal;
    int over;
    int cardCount;
    cardCount = 0;
    over = 1;
    choice = 0;

    /***Ask for bets***/
    printf("Your Life's Worth: $%d\n", player.cash);
    printf("Place your bet(1 - 1000): ");
    scanf("%d", &bet);
    while(bet > MAX_BET || bet > player.cash)
    {
        printf("Bet is too high! Please re-enter your bet for this round.\n");
        scanf("%d", &bet);
    }
    /***Deal Cards***/
    //dealCard() twice for dealer
    cardCount = cardCount + dealCard(deck, &(dealer.hand));//This card is face up
    cardCount = cardCount + dealCard(deck, &(dealer.hand));//This card will be face down
    dealer.hand.hand[1].faceUp = 0;
    printf("Dealer's hand:   ");
    printHand(&(dealer.hand));
    printf("\nDealer has one other face-down card...\n\n");

    //dealCard() twice for player
    cardCount = cardCount + dealCard(deck, &(player.hand));
    cardCount = cardCount + dealCard(deck, &(player.hand));
    printf("The count is an indication of what card will come out next, the higher the count is the higher the chance the next card is a high card and vice versa,\n")
    printf("Count: %d\n",cardCount);
    printf("Your hand:   ");
    printHand(&(player.hand));
    playerTotal = checkForBlackjack(player.hand);
    printf("\n");
    printf("Your hands value: %d\n",playerTotal);
    printf("\n\n");

    dealerTotal = checkForBlackjack(dealer.hand);
    if(playerTotal == 21)
    {
        printf("You got blackjack, you win double!\n");
        choice = -1;
        player.cash = player.cash + 2 * bet;
    }
    while(choice != -1 && playerTotal < 21)
    {

        //if option is to double:
        if(choice == 0)
        {

            /***First play options are to double, hit, or stand***/
            printf("Your options are to hit [1], stand [2] \n");
            scanf("%d", &choice);
            while(choice < 1 || choice > 2)
            {
                printf("Try again: Your options are to hit [1], stand [2] \n");
                scanf("%d", &choice);
            }


        }

        //if option is to hit:
        if(choice == 1)
        {
            cardCount = cardCount + dealCard(deck,&(player.hand));
            printf("Count: %d\n",cardCount);
            printf("Your hand:\t");
            printHand(&(player.hand));
            printf("\n");
            playerTotal = checkForBlackjack(player.hand);
            printf("Your hands value: %d\n",playerTotal);
            choice = 0;
        }

        //if option is to stand:
        if(choice == 2)
        {
            over = 0;
            break;
        }



        /*Subsequent plays in the round are to hit or stand*/

        /*Check after every round*/

        //if player is under 21:
        //
        //keep looping

        //if player is at 21:
        //
        //Blackjack. stop loop and end game

        //if player is over 21:
        //
        //Bust. stop loop and end game
    }
    if(over == 1)
    {
        printf("You went over 21, you lose!\n");
        player.cash = player.cash - bet;
    }
    else
    {
        while(dealerTotal < 16)
        {
            cardCount = cardCount + dealCard(deck,&(dealer.hand));
            dealerTotal = checkForBlackjack(dealer.hand);
        }

        dealer.hand.hand[1].faceUp = 1;
        printf("Dealer's hand:   ");
        printHand(&(dealer.hand));
        printf("\n");
        printf("Dealers value: %d\n",dealerTotal);
        printf("Your hand:   ");
        printHand(&(player.hand));
        printf("\n");
        printf("Your hands value: %d\n",playerTotal);
        printf("\n");


        if(playerTotal <= dealerTotal && dealerTotal < 22)
        {
            printf("You lose!\n");
            player.cash = player.cash - bet;
        }
        else
        {
            printf("You win!\n");
            player.cash = player.cash + bet;
        }
    }





    return player.cash;

}

int checkForBlackjack(Hand hand)
{
    int i;
    int hasAce = 0;
    int total = 0;

    for(i = 0; i < hand.inHand; i++)
    {
        if (hand.hand[i].value == 11 || hand.hand[i].value == 12 || hand.hand[i].value == 13)
        {
            total += 10;
        }
        else if (hand.hand[i].value == 1 && hasAce == 0)
        {
            hasAce = 1;
            total += 11;
        }
        else
        {
            total += hand.hand[i].value;
        }
    }

    if(total > 21 && hasAce == 1)
    {
        total -= 10;
    }

    return total;
}
