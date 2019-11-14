#ifndef __ROUND_H__
#define __ROUND_H__

#include "player.h"
#include "deck.h"
#include "ADTErr.h"


typedef struct Round Round;

typedef enum Mode {LEFT=1, RIGHT, OPPOSITE}Mode;


/* @Description: Create a new Round.
 * @Input: void.
 * @Return: pointer to the new Round or NULL- if unsuccesful.
*/ 
Round* CreateRound();

/* @Description: Destroy the Round.
 * @Input: _round- pointer to the Round created by CreateRound().
 * @Return: void.
*/ 
void DestroyRound(Round* _round);

/* @Description: get card from the deck and deal to the player.
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _index- the index to the Deck from which index deal the card.
 * @Return: 0- if the deal is succeed or -1 if unsucces.
*/ 
int DealCards(Deck* _deck, int _index, Player* _Player);

/* @Description: swap cards between the players.
 * @Input: _arrayPlayer- pointer to array of pointers to players.
 * @Input: _roundNum- the number of the round- the mode shift.
 * @Return: void
*/ 
void shiftCards(Player** _arrayPlayer, int _roundNum);

/* @Description: check which player have 2 club - and he will be the first player to play.
 * @Input: _arrayPlayer- pointer to array of pointers to players.
 * @Return: the index of the begining player in the array of players or -1 if the array is NULL.
*/ 
int checkStart(Player** _arrayPlayer);

/* @Description: check the value of a card - card from suit HEARTS- have value of 1 points and QUEEN SPADE have value of 12 points and the other cards have value of 0.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _card- the card we want to check his value.
 * @Return: the value of the card. or -1 if the Deck is NULL.
*/ 
int GetCardValue(const Deck* _deck, int _card);

/* @Description: each player set one card on the table -check who lose in the trick and update his score.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _arrayPlayer- pointer to array of pointers to players.
 * @Input: _round- pointer to the Round created by CreateRound().
 * @Return: void.
*/ 
void Trick(Player** _arrayPlayer, Round* _round, Deck* _deck);

/* @Description: start the round - each round have 13 tricks.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _arrayPlayer- pointer to array of pointers to players.
 * @Input: _round- pointer to the Round created by CreateRound().
 * @Input: _roundNum- the number of the round.
 * @Input: _score- the array of the total score in the end of the round.
 * @Return: ERR_UNINITINALAIZED- if the _arrayPlayer or the _deck or the _score is NULL.
 * 			ERR_SORT - if the sort not succeed.
 *			ERR_DEAL - if the deal not succeed.
 * 			ERR_OK - if the round is succeed.
*/ 
ADTErr StartRound(Round* _round, Player** _arrayPlayer, int* _score, int _roundNum, Deck* _deck);


/* @Description: Prints the scores of the Round.
 * @Input: _round- pointer to the Round created by CreateRound().
 * @Input: _roundNum- the number of the round.
 * @Return: void.
*/
void PrintRoundScore(const Round* _round, int _roundNum);


#endif /* __ROUND_H__ */

