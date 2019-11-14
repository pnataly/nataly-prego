#ifndef __GAME_H__
#define __GAME_H__

#include "deck.h"
#include "player.h"
#include "ADTErr.h"


typedef struct Game Game;


/* @Description: Create a new Game.
 * @Input: void.
 * @Return: pointer to the new Game or NULL- if unsuccesful.
*/ 
Game* CreateGame();


/* @Description: Destroy the Game.
 * @Input: _game- pointer to the Game created by CreateGame().
 * @Return: void.
*/ 
void DestroyGame(Game* _game);


/* @Description: start the game - start rounds until one of the players pass the 100 points.
 * @Input: _game- pointer to the Game created by CreateGame().
 * @Input: _arrayPlayer- pointer to array of pointers to players.
 * @Return: ERR_UNINITINALAIZED- if the _arrayPlayer or the _game is NULL.
 * 			ERR_SORT - if the sort not succeed.
 *			ERR_GAME_OVER - if one of the players pass the 100 points.
*/ 
ADTErr startGame(Game* _game, Player** _arrayPlayer);


/* @Description: Prints the scores of game.
 * @Input: _game- pointer to the Game created by CreateGame().
 * @Return: void.
*/
void PrintGameScore(const Game* _game);

/* @Description: Prints the winner of game- the player with the lowest points.
 * @Input: _game- pointer to the Game created by CreateGame().
 * @Return: void.
*/
void GetWinner(const Game* _game);

#endif /* __GAME_H__ */

