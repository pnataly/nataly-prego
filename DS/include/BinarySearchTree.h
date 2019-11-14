#ifndef __BINARYSERACHTREE_H__
#define __BINARYSERACHTREE_H__
#include "ADTErr.h"

#define TRUE 1
#define FALSE 0

typedef struct Tree Tree;

typedef enum
{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
}TreeTraverse;


/* @Description: Create a Binary Search Tree.
 * @Input: void.
 * @Return: pointer to the created Binary Search Tree or NULL- if unsuccesful.
*/ 
Tree* TreeCreate(void);

/* @Description: Destroy the Binary Search Tree.
 * @Input: _tree- pointer to Binary Search Tree created by TreeCreate().
 * @Return: void.
*/ 
void TreeDestroy(Tree* _tree);


/* @Description: Add data to the Binary Search Tree. cannot insert duplicate data.
 * @Input: _tree- pointer to Binary Search Tree created by TreeCreate().
 * @Input: _data- the data we want to insert.
 * @Return: 
 *		ERR_OK- if the data add to the Binary Search Tree.
 * 		ERR_UNINITINALAIZED - the pointer to the Binary Search Tree is NULL.
 * 		ERR_ALLOC_FAIL - if the memory allocation of a new Node not succssed.
 * 		ERR_DUP_DATA- 
*/ 
ADTErr TreeInsert(Tree* _tree, int _data);

/* @Description: Check if data found in the Binary Search Tree.
 * @Input: _tree- pointer to Binary Search Tree created by TreeCreate().
 * @Input: _data- the data we want to search in the Binary Search Tree.
 * @Return:
 * 		TRUE- if the data found.
 *		FALSE- if the data not found or if the Binary Search Tree is NULL.
*/
int TreeIsDataFound(Tree* _tree, int _data);

/* @Description: Prints the data in the  Binary Search Tree.
 * @Input: _tree- pointer to Binary Search Tree created by TreeCreate().
 * @Input: _traverseMode: the mode to print the Binary Search Tree: PreOrder, InOrder or PostOrder.
 * @Return: void.
*/
void TreePrint(Tree* _tree, TreeTraverse _traverseMode);

/* @Description: Check if the BST is a full tree.
 * @Input: _tree- pointer to Binary Search Tree created by TreeCreate().
 * @Return: TRUE- if the BST is a full tree or empty.
			FALSE - if the BST is not full.
*/
int isFullTree(Tree* _tree);

/* @Description: Check if the BST is a perfect tree.
 * @Input: _tree- pointer to Binary Search Tree created by TreeCreate().
 * @Return: TRUE- if the BST is a perfect tree or empty.
			FALSE - if the BST is not perfect.
*/
int isPerfectTree(Tree* _tree);
  
#endif /*__BINARYSERACHTREE_H__*/ 
