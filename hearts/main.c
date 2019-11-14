#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "ADTErr.h"


int main()
{
	Game* game;
	int status, i;
	Player** arrayPlayer;
	Player* player;

	arrayPlayer = (Player**)malloc(sizeof(Player*)*NUMPLAYER);
	if(arrayPlayer == NULL)
	{
		return -1;
	}
	for(i=0; i<NUMPLAYER; i++)
	{
		player = CraetePlayer();
		if(player == NULL)
		{
			printf("Error- allocation fault\n");
		}
		arrayPlayer[i] = player;
	}

	game = CreateGame();
	if(game == NULL)
	{
		printf("Error- allocation falut\n");
		return -1;
	}
	printf("*Welcome to Hearts Game!**\n Have Fun!\n");
	status = startGame(game, arrayPlayer);
	if(status == ERR_UNINITINALAIZED || status == ERR_ALLOC_FAIL)
	{
		printf("Error- game fail\n");
		return -1;
	}
	if(status == ERR_GAME_OVER)
	{
		printf("\n!GAME-OVER!\n");
		printf("The table score:\n");
		GetWinner(game);
		printf("----------------\n");
		PrintGameScore(game);
		for(i=0; i<NUMPLAYER; i++)
		{
			DestrtoyPlayer(arrayPlayer[i]);
		}
		free(arrayPlayer);
		DestroyGame(game);
	}
	return 0;
}
