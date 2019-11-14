#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "vector.h"
#include "ADTErr.h"


Stack* StackCreate(size_t _initialSize, size_t _blockSize)
{
	return VectorCreate(_initialSize,_blockSize);
}


void StackDestroy(Stack* _stack)
{
	VectorDestroy(_stack);
	return;
}


ADTErr StackPush(Stack* _stack, int _item)
{

	if(_stack == NULL)
	{
		return ERR_UNINITINALAIZED; 
	}

	return VectorAdd(_stack, _item);

	return ERR_OK;	
}



ADTErr StackPop(Stack* _stack, int* _item)
{
		return VectorDelete(_stack, _item);
}


ADTErr StackTop(Stack* _stack, int* _item)
{
	size_t numOfItems;
	VectorItemsNum(_stack, &numOfItems);
	return VectorGet(_stack, numOfItems, _item);
}



int StackIsEmpty(Stack* _stack)
{
	size_t numOfItems;
	VectorItemsNum(_stack, &numOfItems);

	return !numOfItems;
}


void StackrPrint(Stack* _stack)
{
	VectorPrint(_stack);

}



