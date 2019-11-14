#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "player.h"
#include "round.h"
#include "game.h"
#include "ADTErr.h"


struct Game
{
	int* m_score;
	int m_roundNum;
};

Game* CreateGame()
{
	Game* game;
	int* score;

	game = (Game*)malloc(sizeof(Game));
	if(game == NULL)
	{
		return NULL;
	}
	score = (int*)calloc(sizeof(int),NUMPLAYER);
	if(score == NULL)
	{
		return NULL;
	}

	game->m_score = score;
	game->m_roundNum = 1;
	return game;
}

void DestroyGame(Game* _game)
{
	if(_game == NULL)
	{
		return;
	}
	free(_game->m_score);
	free(_game);
}

ADTErr startGame(Game* _game, Player** _arrayPlayer)
{
	int result;
	Deck* deck;
	Round* round;
	int i;
	if(_game == NULL || _arrayPlayer == NULL)
	{
		return ERR_UNINITINALAIZED;
	}

	deck = CreateDeck();
	if(deck == NULL)
	{
		return ERR_ALLOC_FAIL; 
	}

	round = CreateRound();
	if(round == NULL)
	{
		return ERR_ALLOC_FAIL;
	}

	result = StartRound(round, _arrayPlayer, _game->m_score, _game->m_roundNum, deck);
	while(1)
	{
		if(result == ERR_OK)
		{
			for(i=0; i<NUMPLAYER; i++)
			{
				if(_game->m_score[i] >100)
				{
					DestroyDeck(deck);
					DestroyRound(round);
					return ERR_GAME_OVER;
				}
			}
			printf("\nThe game score after round: %d:\n", _game->m_roundNum);
			printf("-----------------------------\n");
			PrintGameScore(_game);
			_game->m_roundNum++;
			result = StartRound(round, _arrayPlayer, _game->m_score, _game->m_roundNum, deck);
		}
	}
	if(result == ERR_UNINITINALAIZED)
	{
		return ERR_UNINITINALAIZED;
	}
	else if(result == ERR_DEAL)
	{
		return ERR_DEAL;
	}
	return ERR_SORT;
}


void PrintGameScore(const Game* _game)
{
	int i;
	if(_game == NULL)
	{
		return;
	}
	for(i=0; i<NUMPLAYER; i++)
	{
		printf("player%d: %d points\n",(i+1), _game->m_score[i]);
	}
}

void GetWinner(const Game* _game)
{
	int i, min, index;
	min = _game->m_score[0];
	index = 0;
	for(i=1; i<NUMPLAYER; i++)
	{
		if(_game->m_score[i] < min)
		{
			min = _game->m_score[i];
			index = i;
		}
	}
	printf("player%d is Win!\n",(index+1));
}
