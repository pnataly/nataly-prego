#ifndef __STACK_H__
#define __STACK_H__
#include "vector.h"
#include "ADTErr.h"


typedef struct Vector Stack;

Stack* StackCreate(size_t _initialSize, size_t _blockSize);


void StackDestroy(Stack* _stack);



ADTErr StackPush(Stack* _stack, int _item);



ADTErr StackPop(Stack* _stack, int* _item);




ADTErr StackTop(Stack* _stack,int* _item);




int StackIsEmpty(Stack* _stack);




void StackrPrint(Stack* _stack);

#endif /*__STACK_H__*/
