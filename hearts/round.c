#include <stdio.h>
#include <stdlib.h>
#include "round.h"
#include "player.h"
#include "deck.h"
#include "ADTErr.h"

struct Round
{
	int* m_scoreRound;
	int m_start;
	int* m_centerCards;
};


Round* CreateRound()
{
	Round* round;
	int* scoreRound;
	int* centerCards;
	round = (Round*) malloc(sizeof(Round));
	if(round == NULL)
	{
		return NULL;
	}
	scoreRound = (int*)calloc(sizeof(int), NUMPLAYER);
	if(scoreRound == NULL)
	{
		free(round);
		return NULL;
	}
	centerCards = (int*)calloc(sizeof(int), NUMPLAYER);
	if(centerCards == NULL)
	{
		free(scoreRound);
		free(round);
		return NULL;
	}
	round->m_scoreRound = scoreRound;
	round->m_centerCards = centerCards;
	round->m_start = 0;

	return round;
}

void DestroyRound(Round* _round)
{
	if(_round == NULL)
	{
		return;
	}
	
	free(_round->m_scoreRound);
	free(_round->m_centerCards);
	free(_round);
}



int DealCards(Deck* _deck, int _index, Player* _Player)
{
	int result,j;
	if(_deck == NULL || _Player == NULL)
	{
		return -1;
	}
	for(j=_index; j<_index+HANDCARD ;j++)
	{
		result = GiveCard(_deck, j);
		if(result == -1)
		{
				return -1;
		}
		SetCard(_Player, result);
	}
	return 0;
}


void shiftCards(Player** _arrayPlayer, int _roundNum)
{
	int i, j, card;
	if(_arrayPlayer == NULL)
	{
		return; 
	}

	if(_roundNum % NUMPLAYER == LEFT)
	{
		for(j=0; j<NUMPLAYER; j++)
		{
			for(i=0; i<SHIFTCARDS; i++)
			{
				card = GetPlayersPickCard(_arrayPlayer[(j+1)%NUMPLAYER], i);
				SetCard(_arrayPlayer[j], card);
			}
		}
	}

	else if(_roundNum % NUMPLAYER == RIGHT)
	{
		for(j=0; j<NUMPLAYER; j++)
		{
			for(i=0; i<SHIFTCARDS; i++)
			{
				card = GetPlayersPickCard(_arrayPlayer[j], i);
				SetCard(_arrayPlayer[(j+1)%NUMPLAYER], card);
			}
		}
	}

	else if(_roundNum % NUMPLAYER == OPPOSITE)
	{
		for(j=0; j<NUMPLAYER; j++)
		{
			for(i=0; i<SHIFTCARDS; i++)
			{
				card = GetPlayersPickCard(_arrayPlayer[j], i);
				SetCard(_arrayPlayer[(j+2)%NUMPLAYER], card);
			}
		}
	}
}

int checkStart(Player** _arrayPlayer)
{
	int i, j, card, index;
	if(_arrayPlayer == NULL)
	{
		return -1;
	}
	for(i = 0; i<NUMPLAYER; i++)
	{
		for(j=0; j<HANDCARD; j++)
		{
			card = CheckCard(_arrayPlayer[i], j);
			if(card == -1)
			{
				return -1;
			}
			if(card == ((NUMOFCARD/NUMPLAYER)*SHIFTCARDS))
			{
				index = i;
			}
		}
	}
	return index;
}

int GetCardValue(const Deck* _deck, int _card)
{
	if(_deck == NULL)
	{
		return -1;
	}
	if(_card == (NUMOFCARD/NUMPLAYER)-SHIFTCARDS)
	{
		return 12;
	}

	if(_card/HANDCARD == HEARTS)
	{
		return 1;
	}
	return 0;
}

void Trick(Player** _arrayPlayer, Round* _round, Deck* _deck)
{
	int i = 0;
	int card;
	int* Pcard = &card;
	int start, suit, rank, tempRank, j, value;
	if(_arrayPlayer == NULL || _round == NULL || _deck == NULL)
	{
		return;
	}
/* the begining player set a card on the table */
	start = _round->m_start;
	pickCard(_arrayPlayer[start], 1, Pcard);
	_round->m_centerCards[start] = *Pcard;
	suit = card/HANDCARD;
	rank = card%HANDCARD;

	start = (start+1)%NUMPLAYER;
/*the other players set a card on the table */
	while(i < NUMPLAYER-1)
	{
		pickCard(_arrayPlayer[start], 1, Pcard);
		_round->m_centerCards[start] = *Pcard;
		start = (start+1)%NUMPLAYER;
		i++;
	}

	i=0;
/* check who lose in the trick */
	while(i<NUMPLAYER)
	{
		if((_round->m_centerCards[i]/HANDCARD) == suit)
		{
			tempRank =  _round->m_centerCards[i]%HANDCARD;
			if(tempRank > rank)	
			{
				rank = tempRank;
				_round->m_start = i;
			}
		}
		i++;
	}
/*update the score of the loser player */
	for(j=0; j<NUMPLAYER; j++)
	{
		value = GetCardValue(_deck, _round->m_centerCards[j]);
		if(value == -1)
		{
			return; 
		}
		_round->m_scoreRound[_round->m_start] += value;
	}
}

ADTErr StartRound(Round* _round, Player** _arrayPlayer, int* _score, int _roundNum, Deck* _deck)
{
	int card, check;
	int* pCard = &card;
	int i;
	int j=0;
	if(_arrayPlayer == NULL || _deck == NULL || _score == NULL)
	{
		return ERR_UNINITINALAIZED;
	}

	for(i=0; i<NUMPLAYER; i++)
	{
		_round->m_scoreRound[i]=0;
	}

	DeckShuffle(_deck);

	/* deal cards to the players */
	for(i=0; i<NUMPLAYER; i++)
	{	
		card= DealCards(_deck, j, _arrayPlayer[i]);
		if(card == -1)
		{
			return ERR_DEAL;
		}
		j+=HANDCARD;
	}	
	/* sort the cards*/
	for(i=0; i<NUMPLAYER; i++)
	{
		if(SortCard(_arrayPlayer[i]) != ERR_OK)
		{
			return ERR_SORT;
		}	
	}

	if(_roundNum % NUMPLAYER != 0)
	{
		/*each player pick 3 cards */
		for(i=0; i<NUMPLAYER; i++)
		{
			pickCard(_arrayPlayer[i],  SHIFTCARDS, pCard);
		}

		 /* shift 3 card between the players*/
		shiftCards(_arrayPlayer, _roundNum);

		/* sort again after the shift */
		for(i=0; i<NUMPLAYER; i++)
		{
			if(SortCard(_arrayPlayer[i]) != ERR_OK)
			{
				return ERR_SORT;
			}	
		}
	}

	/* check who get 2 clubs */
	check = checkStart(_arrayPlayer);
	if(check == -1)
	{
		return ERR_UNINITINALAIZED;
	}
	_round->m_start = check;

	/* starts 13 tricks */
	for(i=1; i<=HANDCARD; i++)
	{
		Trick(_arrayPlayer, _round, _deck);
	} 

	/* update the score after finish the round */
	for(i=0; i<NUMPLAYER; i++)
	{
		_score[i] += _round->m_scoreRound[i];
	}
	PrintRoundScore(_round, _roundNum);
	return ERR_OK;
}

	
void PrintRoundScore(const Round* _round, int _roundNum)
{
	int i;
	if(_round == NULL)
	{
		return;
	}

	printf("\nThe score of round-%d: \n", _roundNum);
	for(i=0; i<NUMPLAYER; i++)
	{
		printf("Player%d: %d\n", (i+1), _round->m_scoreRound[i]);
	}
}
