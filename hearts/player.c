#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "round.h"
#include "vector.h"
#include "ADTErr.h"

struct Player
{
	Vector* m_cardArray; /* the card hand of the player */
	int* m_pickCard; /* the cards the player pick */
	Type m_type;
};

Player* CraetePlayer()
{
	Player* newPlayer;
	Vector* cardArray;
	int* pickCard;

	newPlayer = (Player*)malloc(sizeof(Player));
	if(newPlayer == NULL)
	{
		return NULL;
	}
	cardArray = VectorCreate(HANDCARD,0);
	if(cardArray == NULL)
	{
		free(newPlayer);
		return NULL;
	}
	pickCard = (int*)malloc(sizeof(int)* SHIFTCARDS);
	if(pickCard == NULL)
	{
		VectorDestroy(cardArray);
		free(newPlayer);
		return NULL;
	}

	newPlayer->m_type = COMPUTER;
	newPlayer->m_cardArray = cardArray;
	newPlayer->m_pickCard = pickCard;

	return newPlayer;
}


void DestrtoyPlayer(Player* _player)
{
	if(_player == NULL)
	{
		return;
	}

	VectorDestroy(_player->m_cardArray);
	free(_player->m_pickCard);
	free(_player);
}	


static int BubbleUp (Vector* _vec, size_t _start, size_t _end)
{
	int j;
	int isSwappedUp = 0;
	int item1 = 0;
	int item2 = 0;
	
	for (j = 0; j < _end-1; j++)
	{ 	
		VectorGet(_vec, j, &item1);
		VectorGet(_vec, j+1, &item2);
		if (item1 > item2)
		{				
			VectorSet(_vec, j, item2);
			VectorSet(_vec, j+1, item1);
			isSwappedUp = 1;
		}	
	}
	return isSwappedUp;
}


static ADTErr BubbleSort(Vector* _vec)
{
	int i, isSwappedUp;
	size_t numOfItems;
	if(_vec == NULL)
	{
		return ERR_UNINITINALAIZED;
	}
	VectorItemsNum(_vec, &numOfItems);

	if(numOfItems == 0)
	{
		return ERR_EMPTY;
	}
	if(numOfItems == 1)
	{
		return ERR_OK;
	}
	for(i=0; i<=numOfItems; i++)
	{	
		isSwappedUp = BubbleUp(_vec, i, numOfItems);
		
		if (!(isSwappedUp))	
		{
			break;
		} 
	}
	return ERR_OK;
}

ADTErr SortCard(Player* _player)
{
	if(_player == NULL)
	{
		return ERR_UNINITINALAIZED;
	}
	if(BubbleSort(_player->m_cardArray) != ERR_OK)
	{
		return ERR_SORT;
	}
	return ERR_OK;
}

void pickCard(Player* _player, int _numOfCard, int* _pickcard)
{ 
	int temp;
	int* Ptemp = &temp;
	int i;
	if(_player == NULL)
	{
		return;
	}

	if(_numOfCard == 1)
	{
		VectorDelete(_player->m_cardArray, _pickcard);
	}

	else if(_numOfCard == 3)
	{
		for(i=0; i<SHIFTCARDS; i++)
		{
			VectorDelete(_player->m_cardArray, Ptemp);
			_player->m_pickCard[i] = *Ptemp;
		}
	}
}


int GetPlayersPickCard(Player* _player, int _index)
{
	if(_player == NULL || _index > SHIFTCARDS)
	{
		return -1;
	}

	return(_player->m_pickCard[_index]);
}


void SetCard(Player* _Player, int _card)
{
	if(_Player == NULL)
	{
		return;
	}

	VectorAdd(_Player->m_cardArray, _card);
}

int CheckCard(Player* _Player, int _index) 
{
	int item;
	int* Pitem = &item;
	if(_Player == NULL || _index > HANDCARD)
	{
		return -1;
	}
	VectorGet(_Player->m_cardArray, _index, Pitem);
	return *Pitem;
}

void PrintPlayerCards(const Deck* _deck, Player* _Player)
{
	int i;
	int item;
	int* Pitem = &item;
	if(_deck == NULL || _Player == NULL)
	{
		return;
	}
	
	for(i=0; i<HANDCARD; i++)
	{
		VectorGet(_Player->m_cardArray, i, Pitem);
		cardPrint(*Pitem);
	}
}

