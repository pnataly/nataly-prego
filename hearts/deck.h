#ifndef __DECK_H__
#define __DECK_H__

#define HANDCARD (NUMOFCARD/NUMPLAYER)
#define NUMPLAYER 4
#define NUMOFCARD 52
#define SHIFTCARDS 3

typedef struct Deck Deck;

typedef enum suit {SPADES=1, HEARTS, DIAMONDS, CLUBS}suit;
typedef enum rank {TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE}rank;


/* @Description: Create a Deck of cards.
 * @Input: void.
 * @Return: pointer to the created Deck or NULL- if unsuccesful.
*/ 
Deck* CreateDeck();


/* @Description: Destroy the Deck.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Return: void.
*/ 
void DestroyDeck(Deck* _deck);


/* @Description: calculate the rank of a card.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _index- the index of the card we want his rank.
 * @Return: the rank of the card or 0 if the deck is NULL or the index is out of range.
*/ 
int getRank(const Deck* _deck, int _index);


/* @Description: calculate the suit of a card.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _index- the index of the card we want his rank.
 * @Return: the suit of the card or 0 if the deck is NULL or the index is out of range.
*/ 
int getSuit(const Deck* _deck, int _index);


/* @Description: shuffle the cards in the Deck.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Return: void.
*/ 
void DeckShuffle(Deck* _deck);


/* @Description: give a card from the deck.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _index- the index of the card we want to get.
 * @Return: the card or -1 if the deck is NULL or the index is out of range.
*/ 
int GiveCard(Deck* _deck, int _index);

/* @Description: Print card.
 * @Input: _card- the card we want to print.
 * @Return: void.
*/
void cardPrint(const int _card);

/* @Description: Prints the Deck.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Return: void.
*/
void deckPrint(const Deck* _deck);

#endif /* __DECK_H__ */
