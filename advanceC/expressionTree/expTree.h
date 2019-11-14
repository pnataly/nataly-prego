/*
 *  @file: expTree.h
 *		a framework for a expression tree.
 *  @author Nataly Prego.
 */
#ifndef __expTree_H__
#define __expTree_H__
#include "hashMap.h"
#include "genericDoubleList.h"
#include "list_itr.h"

typedef struct Node Node;

typdef enum EXP_ERROR
{
	EXP_OK,
	EXP_UNINITIALIZED,
	EXP_INVALID_NAME,
	EXP_INVALID_DATA,
	EXP_INSERT_FAIL,
	EXP_INVALID_FUNC,
	EXP_ALLOC_FAIL
}EXP_ERROR,

typedef enum NodeType
{
	VALUE,
	BINARY_OP,
	UNARY_OP,
	VARIABLE
}NodeType;

/*
 * @brief: create a value Node.
 * @param: _num : the data of the node.
 * @return: pointer to the created node.
 */
Node* CreateNode(int _num);

/*
 * @brief: create a variable Node.
 * @param: _var : the variable of the node.
 * @return: pointer to the created node.
 */
Node* CreateVariableNode(char* _var);

/*
 * @brief: create a binary function Node.
 * @param: _left: the left son of the node.
 * @param: _right: the right son of the node.
 * @param: _binFunc: the binary function.
 * @return: pointer to the created node.
 */
Node* CreateBinaryNode(Node* _left, Node* _right, BinFunc _binFunc);

/*
 * @brief: create a unary function Node.
 * @param: _left: the left son of the node, the right is NULL.
 * @param: _uniFunc: the unary function.
 * @return: pointer to the created node.
 */
Node* CreateUniaryNode(Node* _left, UniFunc _uniFunc);

/*
 * @brief: create expression parser.
 * @return: pointer to the created expression parser.
 */
Exp* ExpressionParser_Create();

/*
 * @brief: destroy the expression parser.
 * @param: _ep: pointer to the expression parser to be destroy.
 * @return - void.
 */
void ExpressionParser_Destroy(Exp** _ep);

/*
 * @brief: add a variable to the expression parser.
 * @param: _ep: pointer to the expression parser.
 * @param: _var: the variable name.
 * @param: _data: the data.
 * @return: EXP_UNINITIALIZED - if the expression parser is NULL.
			EXP_INVALID_DATA -  if the data is NULL.
			EXP_INVALID_NAME - if the name is NULL.
			EXP_INSERT_FAIL - if the insert is fail.
			EXP_OK - if the insert is sucess.
 */
EXP_ERROR ExpressionParser_Add_Var(Exp* _ep, const char* _var, void* _data);

/*
 * @brief: add a binary function to the expression parser.
 * @param: _ep: pointer to the expression parser.
 * @param: _funcName: the binary function name.
 * @param: _binFunc: the function.
 * @return: EXP_UNINITIALIZED - if the expression parser is NULL.
			EXP_INVALID_FUNC -  if the func is NULL.
			EXP_INVALID_NAME - if the name is NULL.
			EXP_INSERT_FAIL - if the insert is fail.
			EXP_ALLOC_FAIL - if the allocation is fail.
			EXP_OK - if the insert is sucess.
 */
EXP_ERROR ExpressionParser_Add_Bin_Func(Exp* _ep, const char* _funcName, BinFunc _binFunc);

/*
 * @brief: add a unary function to the expression parser.
 * @param: _ep: pointer to the expression parser.
 * @param: _funcName: the unary function name.
 * @param: _uniFunc: the function.
 * @return: EXP_UNINITIALIZED - if the expression parser is NULL.
			EXP_INVALID_FUNC -  if the func is NULL.
			EXP_INVALID_NAME - if the name is NULL.
			EXP_INSERT_FAIL - if the insert is fail.
			EXP_ALLOC_FAIL - if the allocation is fail.
			EXP_OK - if the insert is sucess.
 */
EXP_ERROR ExpressionParser_Add_Uni_Func(Exp* _ep, const char* _funcName, UniFunc _uniFunc);

/*
 * @brief: get a string and arrange it in expression tree.
 * @param: _ep: pointer to the expression parser.
 * @param: _string: the string to convert to expression tree.
 * @return: pointer to the expression tree.
 */
Node* Expression_parse(Exp* _ep, char* _string);

/*
 * @brief: calculate the expression tree.
 * @param: _ep: pointer to the expression parser.
 * @param: _root: pointer to the expression tree.
 * @return: the result of the expression tree.
 */
double ExpressionParser_Calc(Exp* _ep, Node* _root);


#endif /*__expTree_H__*/ 

