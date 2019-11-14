#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "ADTErr.h"

struct Deck
{
	int* m_card;
};

Deck* CreateDeck()
{
	int i;
	Deck* deck;
	int* array;
	deck = (Deck*)malloc(sizeof(Deck));
	if(deck == NULL)
	{
		return NULL;
	}
	array = (int*)malloc(sizeof(int)*NUMOFCARD);
	if(array == NULL)
	{
		return NULL;
	}

	for(i=0; i <NUMOFCARD; i++)
 	{ 		  	
	 	array[i] = i;
 	}

	deck->m_card = array;
	
	return deck;	
}

void DestroyDeck(Deck* _deck)
{
	if(_deck == NULL)
	{
		return;
	}

	free(_deck->m_card);
	free(_deck);
}

int getRank(const Deck* _deck, int _index)
{
	if(_deck == NULL || _index >= NUMOFCARD)
	{
		return 0;
	}
	
	return ((_deck->m_card[_index])%HANDCARD);
}

int getSuit(const Deck* _deck, int _index)
{
	if(_deck == NULL || _index >= NUMOFCARD)
	{
		return 0;
	}

	return _deck->m_card[_index]/HANDCARD;
}


void DeckShuffle(Deck* _deck)
{
	int i, from, to, card;
	if(_deck == NULL)
	{
		return;
	}

	for(i = 0; i < 100; i++)
	{
		from = (rand() % NUMOFCARD);
		to = (rand() % NUMOFCARD);
		card = _deck->m_card[from];
		_deck->m_card[from] = _deck->m_card[to];
		_deck->m_card[to] = card;
	}
}

int GiveCard(Deck* _deck, int _index)
{
	if(_deck == NULL || _index > NUMOFCARD)
	{
		return -1;
	}
	return _deck->m_card[_index];
}

void cardPrint(const int _card)
{
	char *suits_str[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	char *ranks_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K", "A"};

	printf("%s of %s\n", suits_str[_card/HANDCARD], ranks_str[_card%HANDCARD]);
}

void deckPrint(const Deck* _deck)
{
	int i;
	char *suits_str[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	char *ranks_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K", "A"};
	if(_deck == NULL)
	{
		return;
	}
	for(i=0; i<NUMOFCARD; i++)
	{
		printf("i: %d, %s of %s\n",i, suits_str[getSuit(_deck, i)], ranks_str[getRank(_deck, i)]);
	} 
}
