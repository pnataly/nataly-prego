#include <stdlib.h>
#include "genericBst.h"
#define END &_tree->m_end

typedef struct Node Node;

struct Node
{
	void* m_data;
	Node* m_left;
	Node* m_right;
	Node* m_father;
};
	

struct BSTree
{		
	LessComparator m_less;
	Node m_end; /*left is to root*/
};


static void NodeDestroy(Node* _node, void (*_destroyer)(void*))
{
	if(_node == NULL)
	{
		return;
	}
	if(_node == _node-> m_left)
	{
		_node->m_left = NULL;
	}
	if(_destroyer != NULL)
	{
		_destroyer(_node->m_data);
	}
	NodeDestroy(_node->m_left, _destroyer);
	NodeDestroy(_node->m_right, _destroyer);
	free(_node);
}

static Node* CreateNode(void* _item)
{
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->m_data = _item;
	newNode->m_left = NULL;
	newNode->m_right = NULL;
	return newNode;
}

static BSTreeItr FindLeft(Node* _node)
{
	if(_node == NULL)
	{
		return NULL;
	}
	while(_node->m_left != _node)
	{
		_node = _node->m_left;
	}
	return _node;
}

static void NodeInsertion(Node* _node, Node* _newNode, LessComparator _less)
{
	while(1)
	{
		/*if True-go left*/
		if(_less(_newNode->m_data, _node->m_data)) 
		{
			if(_node->m_left == NULL) 
			{
				_node->m_left = _newNode;
				_newNode->m_father = _node;
				return;
			}
			if(_node->m_left == _node) 
			{
				_node->m_left = _newNode;
				_newNode->m_father = _node;
				_newNode->m_left = _newNode; /* new begin */
				return;
			}
			_node = _node->m_left;
		}
		/*if False-go right*/
		else 
		{
			if(_node->m_right == NULL) 
			{
				_node->m_right = _newNode;
				_newNode->m_father = _node;
				return;
			}
			_node = _node->m_right;
		}
	}
}

static BSTreeItr InEach(Node *_node, ActionFunction _action, void* _context)
{
	Node* someNode;
	if(_node->m_left != NULL  && _node->m_left != _node)
	{
		someNode = InEach(_node->m_left,_action,_context);
	}
	if (_action(_node->m_data, _context) == 0)
	{
		return _node;
	}
	if(_node->m_right != NULL)
	{
		someNode = InEach(_node->m_right,_action,_context);
	}
	return someNode;
}

static BSTreeItr PreEach(Node *_node, ActionFunction _action, void* _context)
{
	Node* someNode;

	if(_node == NULL)
	{
		return _node;
	}
	if (_action(_node->m_data, _context) == 0) 
	{
		return _node;
	}
	if(_node->m_left != NULL  && _node->m_left != _node)
	{
		someNode = PreEach(_node->m_left,_action,_context);
	}
	if(_node->m_right != NULL)
	{
		someNode = PreEach(_node->m_right,_action,_context);
	}
	return someNode;
}

static BSTreeItr PostEach(Node *_node, ActionFunction _action, void* _context)
{
	Node* someNode;

	if(_node == NULL)
	{
		return _node;
	}
	if(_node->m_left != NULL  && _node->m_left != _node)
	{
		someNode = PostEach(_node->m_left,_action,_context);
	}
	if(_node->m_right != NULL)
	{
		someNode = PostEach(_node->m_right,_action,_context);
	}
	if (_action(_node->m_data, _context) == 0) 
	{
		return _node;
	}
	return someNode;
}

BSTree* BSTree_Create(LessComparator _less)
{
	BSTree* newBSTree;
	newBSTree = (BSTree*)calloc(1,sizeof(BSTree));
	if (newBSTree == NULL)
	{
		return NULL;
	}
	newBSTree->m_less =_less;
	return newBSTree;
}

void BSTree_Destroy(BSTree** _tree, void (*_destroyer)(void*))
{
	if (_tree == NULL || *_tree == NULL) 
	{
		return;
	}
	NodeDestroy((*_tree)->m_end.m_left, _destroyer);
	free(*_tree);
	*_tree = NULL;
}


BSTreeItr BSTree_Insert(BSTree* _tree, void* _item)
{
	Node* newNode;
	if (_tree == NULL)
	{
		return NULL;
	}
	if(_item == NULL)
	{
		return END;
	}
	/*if allocation failed*/
	if ((newNode = CreateNode(_item)) == NULL)
	{
		return END; 
	}
	/* if the tree is empty */
	if (_tree -> m_end.m_left == NULL)
	{
		_tree -> m_end.m_left = newNode;
		newNode -> m_left = newNode; 	/*the begin next is begin*/
		newNode -> m_father = END;
		return newNode;
	}
	NodeInsertion(_tree->m_end.m_left ,newNode ,_tree->m_less); 
	return newNode;
}

BSTreeItr BSTreeItr_Next(BSTreeItr _itr)
{
	Node* Son = _itr;
	Node* Father;
	if(_itr == NULL)
	{
		return NULL;
	}
	if(Son->m_right != NULL)
	{
		return FindLeft(Son->m_right);
	}
	Father = Son->m_father;
	while(Father->m_right == Son)
	{
		Son = Father;
		Father = Son->m_father;
	}
	return Father;
}


BSTreeItr BSTreeItr_Prev(BSTreeItr _itr)
{
	Node* Son = _itr;
	Node* Father;
	if (_itr == NULL)
	{
		return NULL;
	}
	if (Son->m_left != NULL)
	{
		return FindLeft(Son->m_left);
	}
	Father = Son->m_father;
	while(Father->m_left == Son)
	{
		Son = Father;
		Father = Son->m_father;
	}
	return Father;
}

BSTreeItr BSTreeItr_Begin(const BSTree* _tree)
{
	Node* node;
	if(_tree == NULL)
	{
		return NULL;
	}
	/* if the tree is empty - return end */
	if(_tree -> m_end.m_left == NULL) 
	{
		return (BSTreeItr)END;
	}
	node = _tree->m_end.m_left;
	while(node->m_left != node)
	{
		node = node->m_left;
	}
	return node;
}

BSTreeItr BSTreeItr_End(const BSTree* _tree)
{
	if (_tree == NULL)
	{
		return NULL;
	}
	return (BSTreeItr)END;
}

void* BSTreeItr_Get(BSTreeItr _itr)
{
	Node* node = _itr;
	if(_itr == NULL)
	{
		return NULL;
	}
	if(node->m_data == NULL)
	{
		return NULL;
	}
	return node->m_data;
}

int BSTreeItr_Equals(BSTreeItr _a, BSTreeItr _b)
{
	if (_a == NULL || _b == NULL)
	{
		return FALSE;
	}
	return(_a == _b);
}

BSTreeItr BSTree_FindFirst(const BSTree* _tree, PredicateFunction _predicate, void* _context)
{	
	Node* status;
	if (_tree == NULL || _predicate == NULL || _tree->m_end.m_left == NULL)
	{
		return NULL;
	}
	status = InEach(BSTreeItr_Begin(_tree), _predicate, _context);
	return (status == NULL? (BSTreeItr)END : status);
}


BSTreeItr BSTree_ForEach(const BSTree* _tree, TreeTraversalMode _mode, ActionFunction _action, void* _context)
{
	Node* node;
	if(_tree == NULL || _action == NULL)
	{
		return NULL;
	}
	switch (_mode)
	{
		case BSTREE_TRAVERSAL_PREORDER:
				node = PreEach(_tree->m_end.m_left, _action, _context);
				break;

		case BSTREE_TRAVERSAL_INORDER:
				node = InEach(_tree->m_end.m_left, _action, _context);
				break;

		case BSTREE_TRAVERSAL_POSTORDER:
			node = PostEach(_tree->m_end.m_left, _action, _context);
			break;
	}
	return ((node == NULL)? (BSTreeItr)END:(void *)node); 
}


