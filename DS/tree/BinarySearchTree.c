#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "ADTErr.h"
#define MAGIC_NUMBER 0XBEEFBEEF

typedef struct Node Node;

struct Node
{
	int m_data;
	Node* m_left;
	Node* m_right;
	Node* m_father;
};

struct Tree
{
	unsigned int m_magicNumber;
	Node* m_root;
};


static Node* CreateNode(int _data) 
{ 
	Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL)
	{
		return NULL;
	}
    newNode->m_data = _data; 
	newNode->m_left = NULL;
	newNode->m_right = NULL;

    return newNode; 
} 

static void DestroySubTree(Node* _node)
{
	if(_node == NULL)
	{
		return;
	}
	DestroySubTree(_node->m_left);
	DestroySubTree(_node->m_right);
	free(_node);
}


static Node* FindLocation(Node* _node, int _data)
{
    if (_node == NULL)
	{
		return _node; 
	}
  
    if (_data < _node->m_data)
	{ 
        _node->m_left = FindLocation(_node->m_left, _data); 
	}
    if (_data >  _node->m_data) 
	{
        _node->m_right = FindLocation(_node->m_right, _data); 
  	}

    return _node; 
}

Tree* TreeCreate(void)
{
	Tree* tree;
	tree = (Tree*)malloc(sizeof(Tree));
	if(tree == NULL)
	{
		return NULL;
	}

	tree->m_magicNumber = MAGIC_NUMBER;
	tree->m_root = NULL;

	return tree;
}

void TreeDestroy(Tree* _tree)
{
	if(_tree == NULL ||_tree->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	_tree->m_magicNumber = 0;
	
	DestroySubTree(_tree->m_root);
	free(_tree);
	return;

}

ADTErr TreeInsert(Tree* _tree, int _data)
{ 
	Node* newNode;
    if(_tree == NULL || _tree->m_magicNumber != MAGIC_NUMBER) 
	{
		return ERR_UNINITINALAIZED;
	}
	newNode = CreateNode(_data);
	if(newNode == NULL)	
	{
		return ERR_ALLOC_FAIL;
	}

	if(_tree->m_root == NULL)
	{
		_tree->m_root = newNode;
	}

	_tree->m_root = FindLocation(_tree->m_root, _data);

	return ERR_OK;
}
 

static int Search(Node* _node, int _data)
{
	if(_node == NULL)
	{
		return FALSE;
	}
	if(_node->m_data == _data)
	{
		return TRUE;
	}
	if(_node->m_data >_data)
	{
		return Search(_node->m_left, _data);
	}
	return Search(_node->m_right, _data);
}


int TreeIsDataFound(Tree* _tree, int _data)
{
	if(_tree == NULL)
	{
		return FALSE;
	}
	return Search(_tree->m_root, _data);
}


static void PostPrint(const Node* _node)
{
	if(_node == NULL)
	{
		return;
	}
	PostPrint(_node->m_left); 
	PostPrint(_node->m_right);   
	printf("%d", _node->m_data);
}

static void PrePrint(const Node* _node)
{
	if(_node == NULL)
	{
		return;
	}
	printf("%d", _node->m_data);
	PrePrint(_node->m_left);  
	PrePrint(_node->m_right); 

}

static void InPrint(const Node* _node)
{
	if(_node == NULL)
	{
		return;
	}
	InPrint(_node->m_left);  
	printf("%d", _node->m_data);
	InPrint(_node->m_right);  
}

void TreePrint(Tree* _tree, TreeTraverse _traverseMode)
{
	if(_tree == NULL)
	{
		return;
	}
	switch(_traverseMode)
	{
		case PRE_ORDER:
				printf("The elments in the tree in PreOrder:\n");
				PrePrint(_tree->m_root);
				printf("\n"); 
				break;
				
		case IN_ORDER:
				printf("The elments in the tree in InOrder:\n");
				InPrint(_tree->m_root);
				printf("\n"); 
				break;

		case POST_ORDER:
				printf("The elments in the tree in PostOrder:\n");
				PostPrint(_tree->m_root);
				printf("\n"); 
				break;
	}

}
static int isFullSubTree(Node* _node)
{
    if (_node == NULL)
	{
        return TRUE; 
	}

    if (_node->m_left == NULL && _node->m_right == NULL)
	{
    	return TRUE; 
	}
    if ((_node->m_left) && (_node->m_right)) 
	{
        return (isFullSubTree(_node->m_left) && isFullSubTree(_node->m_right)); 
  	}

    return FALSE;
}


int isFullTree(Tree* _tree) 
{ 
    if(_tree == NULL)
	{
		return TRUE;
	}
	return isFullSubTree(_tree->m_root);
} 

/*TODO isSimilarTree */

static int High(Node* _node)
{
	int high = 0;
	while(_node != NULL)
	{
		high++;
		_node=_node->left;
	}
	return high;
}


static int isPerfectSubTree(Node* _node)
{
	if (_node == NULL)
	{
        return TRUE; 
	}

	if (_node->m_left == NULL && _node->m_right == NULL)
	{
    	return TRUE; 
	}
	
	if (_node->m_left == NULL || _node->m_right == NULL)
	{
    	return FALSE; 
	}

	if(_node->m_left != NULL && _node->m_right != NULL)
	{
		return isPerfectSubTree(_node->m_left) && isPerfectSubTree(_node->m_right);
	}

}

int isPerfectTree(Tree* _tree) 
{
 	if(_tree == NULL)
	{
		return TRUE;
	}
	return isPerfectSubTree(_tree->m_root);
}
