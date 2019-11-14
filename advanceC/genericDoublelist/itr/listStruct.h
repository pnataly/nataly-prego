#ifndef __LISTSTRUCT_H__
#define __LISTSTRUCT_H__

typedef struct Node Node;

struct Node 
{
	void* m_data;
	Node* m_next;
	Node* m_prev;
};


struct List
{
	Node m_head;
	Node m_tail;
};

void PushToList(Node* _newNode, Node* _next);


#endif /*__LISTSTRUCT_H__*/ 
