
#define TRUE 1
#define FALSE 0


static int findDepth(Node* _node) 
{ 
   int depth = 0; 
   while (_node != NULL) 
   { 
      depth++; 
      _node = _node->left; 
   } 
   return depth; 
} 
  
static int IsPerfectRec(Node* _root, int _depth) 
{ 
	int level = 0;

    if (_root == NULL)
	{ 
        return TRUE; 
	} 
    if (_root->left == NULL && _root->right == NULL)
	{ 
		if(_depth == level+1)
		{
		    return TRUE; 
		}
		return FALSE;
	}

    if (_root->left == NULL || _root->right == NULL)
	{ 
        return FALSE; 
	}

    return IsPerfectRec(_root->left, _depth, level+1) && IsPerfectRec(_root->right, _depth, level+1); 
} 
  

int isPerfect(Node* _root) 
{ 
  	int depth;
	depth = findDepth(_root); 
	return IsPerfectRec(_root, depth); 
} 
