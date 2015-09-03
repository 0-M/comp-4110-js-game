#define maxHandSize 11 //Max hand size for given game, currently for Blackjack(four A's,four 2's,three 3's)

typedef struct Card
{
    int faceUp; //0 if face down 1 if face up
    int value;
    char suit;
} Card, *CardPtr;

typedef struct Deck
{
	int top;
    int cardsLeft;
    Card* deck;
} Deck, *DeckPtr;

typedef struct Hand
{
    int inHand;
    Card hand[maxHandSize];
} Hand, *HandPtr;


/*Initializes deck to play with with either 1 deck of 52 cards, or 2 decks, etc*/
DeckPtr initDeck(int numberOfDecks);

/*Pushes a card onto the deck*/
void push(DeckPtr deck, Card data);

/*Pops a card off from the top of the deck*/
Card pop(DeckPtr stack);

/*Shuffles the deck*/
DeckPtr shuffleCards(DeckPtr deck);

/*Deals a card to a hand*/
int dealCard(DeckPtr deck, HandPtr hand);

void printDeck(DeckPtr deck);

void printCard(Card card);

void printHand(HandPtr hand);

void swapCards(CardPtr a,CardPtr b);

/*Empties the deck*/
void empty(DeckPtr deck);

/*Destoys the deck*/
void destroyDeck(DeckPtr deck);
