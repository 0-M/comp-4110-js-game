#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Deck.h"

DeckPtr initDeck(int numberOfDecks)
{
	DeckPtr deck = (DeckPtr)malloc(sizeof(deck));
	deck->cardsLeft = 52 * numberOfDecks;
	deck->top = -1;
	deck->deck = (CardPtr)malloc(sizeof(Card) * 52 * numberOfDecks);
	return deck;
}

void push(DeckPtr deck, Card data)
{
	if (deck == NULL)
	{
		printf("\nDeck pointer is null, closing program\n");
		exit(1);
	}
	if(deck->top + 1 > deck->cardsLeft)
	{
		printf("Deck is full, can no longer push\n");
		return;
	}

	deck->top += 1;
	deck->deck[deck->top] = data;

	return;
}

Card pop(DeckPtr deck)
{
	Card data;
	if (deck == NULL)
	{
		printf("\nDeck pointer is null, closing program\n");
		exit(1);
	}
	if (deck->top < 0)
	{
		printf("\nCannot pop at negative location, closing program\n");
		exit(1);
	}

	data = deck->deck[deck->top];
	deck->top -= 1;

	return data;
}

void printDeck(DeckPtr deck)
{
    int i;
    for(i = 0; i < deck->cardsLeft; i++)
    {
        if(deck -> deck[i].value == 1)
        {
            printf("%s,%c\n","Ace",deck -> deck[i].suit);
        }
        else if(deck -> deck[i].value == 11)
        {
                printf("%s,%c\n","Jack",deck -> deck[i].suit);
        }
        else if(deck -> deck[i].value == 12)
        {
                printf("%s,%c\n","Queen",deck -> deck[i].suit);
        }
        else if(deck -> deck[i].value == 13)
        {
                printf("%s,%c\n","King",deck -> deck[i].suit);
        }
        else
        {
            printf("%d,%c\n",deck -> deck[i].value,deck -> deck[i].suit);
        }

    }
}

void printCard(Card card)
{
	if(card.faceUp == 1)
	{
		if(card.value == 1)
		{
			printf("[%s,%c]", "Ace", card.suit);
		}
		else if(card.value == 11)
		{
			printf("[%s,%c]", "Jack", card.suit);
		}
		else if (card.value == 12)
		{
			printf("[%s,%c]", "Queen", card.suit);
		}
		else if (card.value == 12)
		{
			printf("[%s,%c]", "King", card.suit);
		}
		else if (card.value > 1 && card.value < 11)
		{
			printf("[%d,%c]", card.value, card.suit);
		}
	}
}

void printHand(HandPtr hand)
{
	int i;
	for(i = 0; i < 11; i++)
	{
		printCard(hand->hand[i]);
	//	printf("  ");
	}

}

DeckPtr shuffleCards(DeckPtr deck) //Shuffles the Deck
{
    srand(time(NULL));
    int i;
    for(i = 0; i < 10000; i++)
    {
        swapCards(&(deck -> deck[rand() % deck->cardsLeft]), &(deck -> deck[rand() % deck->cardsLeft]));
    }

	return deck;
}

void swapCards(CardPtr a, CardPtr b)
{
    Card hold;
    hold = *b;
    *b = *a;
    *a = hold;
}

int dealCard(DeckPtr deck, HandPtr hand)
{
    int i;
    i = 0;

    Card toDeal;
    toDeal = pop(deck);

	hand->hand[hand->inHand] = toDeal;
	hand->inHand = hand->inHand + 1;

	if(toDeal.value > 1 && toDeal.value < 7)
    {
        return 1;
    }
    else if(toDeal.value > 6 && toDeal.value < 10)
    {
        return 0;
    }
    else
    {
        return -1;
    }



}

void empty(DeckPtr deck)
{
	if (deck == NULL)
		printf("Deck already destroyed.\n");
	deck->cardsLeft = 0;
	deck->deck = NULL;

	return;
}

void destroyDeck(DeckPtr deck)
{
	free(deck->deck);
	//free(deck); already freed?
	return;
}
