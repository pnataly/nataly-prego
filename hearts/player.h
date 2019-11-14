#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <stdio.h>
#include "deck.h"
#include "vector.h"
#include "ADTErr.h"

typedef struct Player Player;

typedef enum Type {COMPUTER, HUMAN}Type;


/* @Description: Create a new player.
 * @Input: void.
 * @Return: pointer to the new player or NULL- if unsuccesful.
*/ 
Player* CraetePlayer();

/* @Description: Destroy the player.
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Return: void.
*/ 
void DestrtoyPlayer(Player* _player);

/* @Description: sorting the hand card of the player using Bubble sort.
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Return: ERR_UNINITINALAIZED - if the player is NULL.
 * 			ERR_SORT - if the sort not succeed.
 * 			ERR_OK - if the sort succeed.
*/ 
ADTErr SortCard(Player* _player);

/* @Description: pick card from the player hand card.
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Input: _numOfCard- the amount of card to pick.
 * @Input: _pickcard- the card we pick.
 * @Return: void
*/ 
void pickCard(Player* _player, int _numOfCard, int* _pickcard);


/* @Description: the player take a card.
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Input: _card- the card for the player.
 * @Return: void.
*/
void SetCard(Player* _Player, int _card);

/* @Description: gets the player shift cards.
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Input: _index- the index of the card.
 * @Return: the card the player want to shift.
*/
int GetPlayersPickCard(Player* _player, int _index);

/* @Description: get player card.
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Input: _index- the index of the card.
 * @Return: the card or -1 if the Player is NULL or the index is out of range.
*/
int CheckCard(Player* _Player, int _index);

/* @Description: Prints the hand card of the player.
 * @Input: _deck- pointer to Deck created by CreateDeck().
 * @Input: _player- pointer to the player created by CraetePlayer().
 * @Return: void.
*/
void PrintPlayerCards(const Deck* _deck, Player* _Player);

#endif /* __PLAYER_H__ */
