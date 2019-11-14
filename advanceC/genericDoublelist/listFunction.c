#include <stdio.h>
#include "listFunction.h"


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
	if(_begin == NULL || _end == NULL || _predicate == NULL)
	{
		return NULL;
	}
	i = _begin;

	if(Equals(_begin, _end))
	{
		return _end;
	}

	while(i != _end)
	{
		if(_predicate(ListItr_Get(i), _context) == 1)
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

