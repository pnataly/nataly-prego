#include <stdio.h>
#include "listFunction.h"
/*
int Predicate(void * _element, void* _context)
{
	if (_element == NULL)
	{
		return 0;
	}

	return 1;
}

int Action(void* _element, void* _context)
{
	if (_element == NULL)
	{
		return 0;
	}
	
	printf("%d, ", *(int*)_element);
	return 1;
}

int Less(void* _a, void* _b)
{
	if (_a == NULL || _b == NULL)
	{
		return FALSE;
	}
	if (_a < _b)
	{
		return TRUE;
	}
	return FALSE;
}

int Equals(void* _a, void* _b)
{
	if (_a == NULL || _b == NULL)
	{
		return FALSE;
	}
	if (_a == _b)
	{
		return TRUE;
	}
	return FALSE;
}
*/
ListItr ListItr_ForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
	ListItr i;
	void* pData;
	if(_begin == NULL || _end == NULL || _action == NULL)
	{
		return NULL;
	}
	i = _begin;
	
	while(i != _end && i != ListItr_Next(i))
	{
		pData = ListItr_Get(i);
		if(_action(pData, _context) == 0)
		{	
			break;	
		}
		i = ListItr_Next(i);
	}
	return i;
}

ListItr ListItr_FindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	ListItr i;

	if (_begin == NULL || _end == NULL || _predicate == NULL)
	{
		return NULL;
	}
	i = _begin;
	while (i != _end)
	{
		if (_predicate(ListItr_Get(i), _context) == 1)
		{
			return i;
		}
		i = ListItr_Next(i);
	}
	return _end;
}

size_t ListItr_CountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	size_t count = 0;
	ListItr i;
	if(_begin == NULL || _end == NULL || _predicate == NULL)
	{
		return 0;
	}
	i = _begin;

	while(i != _end)
	{
		if(_predicate(ListItr_Get(i), _context) == 1)
		{
			count++;
		}
		i = ListItr_Next(i);
	}
	return count;
}

