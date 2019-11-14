#include <string.h> 
#include <ctype.h> /*isdigit*/
#include "list_itr.h"
#include <stdlib.h>
#include "expTree.h"
#define NULL_ERROR 0
#define SIZE 128
#define TRUE 1
#define FALSE 0

typedef union Func
{
	BinFunc m_binFunc;
	UniFunc m_uniFunc;		
}Func;

typedef union Data
{
	double m_value;
	BinFunc m_bin;
	UniFunc m_uni;
	char name[256];
}Data;

typedef struct Node
{
	NodeType m_type;
	Data m_data;
	Node* m_left;
	Node* m_right;
}Node;

typedef struct Exp
{
	HashMap* m_var;
	HashMap* m_func;
}Exp;


typedef struct Function
{
	NodeType m_funcFlag;
	Func m_func;
}Function;




/**********Statics-Functions*************/
static double Add(double _num1, double _num2);
static double Sub(double _num1, double _num2);
static double Mul(double _num1, double _num2);
static double Div(double _num1, double _num2);
static double Pow(double _num1, double _num2);
static void ValDestroy(void* _value);
static void FuncDestroy(void* _func);
static void KeyDestroy(void* _key);
static int keysEqualFunc(const void* _firstKey, const void* _secondKey);
static double CalcRec(Exp* _ep, Node* _root);
static void AddFunc(HashMap* _map);

/***********Main-Functions**************/

Node* CreateNode(int _num)
{
	Node* node = (Node*) malloc(sizeof(Node);
	if(node == NULL)
	{
		return NULL;
	}
	node->m_type = VALUE;
	node->m_data.m_value = num;
	node->m_left = NULL;
	node->m_right = NULL;
	return node;
}

Node* CreateVariableNode(char* _var)
{
	Node* node;
	if(_var == NULL)
	{
		return NULL;
	}
	node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		return NULL;
	}
	node->m_type = VARIABLE;
	strcpy(node->m_data.name, _var);
	node->m_left = NULL;
	node->m_right = NULL;
	return node;
}

Node* CreateBinaryNode(Node* _left, Node* _right, BinFunc _binFunc)
{
	Node* node;
	if(_left == NULL || _right == NULL || _binFunc == NULL)
	{
		return NULL;
	}
	node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		return NULL;
	}
	node->m_type = BINARY_OP;
	node->m_data.m_bin = _binFunc;	
	node->m_right = _right;
	node->m_left = _left;
	return node;
}

Node* CreateUniaryNode(Node* _left, UniFunc _uniFunc)
{
	Node* node;
	if(_left == NULL || _uniFunc == NULL)
	{
		return NULL;
	}
	node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		return NULL;
	}
	node->m_type = BINARY_OP;
	node->m_data.m_uni = _uniFunc;	
	node->m_right = NULL;
	node->m_left = _left;
	return node;
}


double ExpressionParser_Calc(Exp* _ep, Node* _root)
{
	if(_ep == NULL || _root == NULL)
	{
		return NULL_ERROR;
	}
	return CalcRec(_ep, _root);
}

Exp* ExpressionParser_Create()
{
	HashMap* hashFunc;
	HashMap* hashVar;
	Exp* exp;
	hashFunc = HashMap_Create(SIZE, hashFunc, keysEqualFunc);
	if(hashFunc == NULL)
	{
		return NULL;
	}
	hashVar = HashMap_Create(SIZE, hashFunc, keysEqualFunc);
	if(hashFunc == NULL)
	{
		HashMap_Destroy(&hashFunc, KeyDestroy, ValDestroy);
		return NULL;
	}
	exp = (Exp*) malloc(sizeof(Exp));
	if(exp == NULL)
	{
		HashMap_Destroy(&hashFunc, KeyDestroy, FuncDestroy);
		HashMap_Destroy(&hashVar, KeyDestroy, ValDestroy);
		return NULL;
	}
	AddFunc(funcMap);
	exp->m_var = hashVar;
	exp->m_func = hashFunc;
	return exp;
}

void ExpressionParser_Destroy(Exp** _ep)
{
	if(_ep == NULL || *_ep == NULL)
	{
		return;
	}
	HashMap_Destroy(&(*_ep)->m_var, keyDestroy, valDestroy);
	HashMap_Destroy(&(*_ep)->m_func, keyDestroy, FuncDestroy);
	free(*_ep);
	*_ep = NULL;
}

EXP_ERROR ExpressionParser_Add_Var(Exp* _ep, const char* _var, void* _data)
{
	if(_ep == NULL)
	{
		return EXP_UNINITIALIZED;
	}
	if(_data == NULL)
	{
		return EXP_INVALID_DATA;
	}
	if(_var == NULL)
	{
		return EXP_INVALID_NAME;
	}
	if(HashMap_Insert(_ep->m_var, (void*)_var, (void*)_data) != MAP_SUCCESS)
	{
		return EXP_INSERT_FAIL;
	}
	return EXP_OK;
}

EXP_ERROR ExpressionParser_Add_Bin_Func(Exp* _ep, const char* _funcName, BinFunc _binFunc)
{
 	Function* func;
	if(_ep == NULL)
	{
		return EXP_UNINITIALIZED;
	}
	if(_funcName == NULL)
	{
		return EXP_INVALID_NAME;
	}
	if(_binFunc == NULL)
	{
		return EXP_INVALID_FUNC;
	}
	func = (Function*)malloc(sizeof(Function));
	if(func == NULL)
	{
		return EXP_ALLOC_FAIL;
	}
	func->m_funcFlag = BINARY_OP;
	func->m_func.m_binFunc = _binFunc;	
	if((HashMap_Insert(_ep->m_func, _funcName, func)) != MAP_SUCCESS)
	{
		return EXP_INSERT_FAIL;
	}
	return EXP_OK;
}

EXP_ERROR ExpressionParser_Add_Uni_Func(Exp* _ep, const char* _funcName, UniFunc _uniFunc)
{
 	Function* func;
	if(_ep == NULL)
	{
		return EXP_UNINITIALIZED;
	}
	if(_funcName == NULL)
	{
		return EXP_INVALID_NAME;
	}
	if(_uniFunc == NULL)
	{
		return EXP_INVALID_FUNC;
	}
	
	func = (Function*)malloc(sizeof(Function));
	if(func == NULL)
	{
		return EXP_ALLOC_FAIL;
	}
	func->m_funcFlag = UNARY_OP;
	func->m_func.m_uniFunc = _uniFunc;	
	if((HashMap_Insert(_ep->m_func, _funcName, func)) != MAP_SUCCESS)
	{
		return EXP_INSERT_FAIL;
	}
	return EXP_OK;
}

Node* Expression_parse(Exp* _ep, char* _string)
{
	double num;
	Node* node;
	Node* left;
	Node* right;
	List* list;
	char* token;
	void* pValue;
	if(_ep == NULL || _string == NULL)
	{
		return NULL;
	}
	list = ListCreate();
	if(list == NULL)
	{
		return NULL;
	}
	token = strtok(_string, " ");
	if(token == NULL)
	{
		ListDestroy(&list, NULL);
	}
	while(token)	
	{
		if(isdigit(*token))
		{
			num = atof(token); /*convert string to double */
			node = CreateNode(num);
			if(node == NULL)
			{
				return NULL;
			}
		}
		else if(HashMap_Find(_ep->m_func, token, &pValue) == MAP_SUCCESS) 
		{
			if(((Node*)pValue)->m_type == BINARY_OP)
			{
				ListPopTail(list, (void**)&left);
				ListPopTail(list, (void**)&right);
				node = CreateBinaryNode(left, right,((Node*)pValue)->m_data.m_bin);
				if(node == NULL)
				{
					return NULL;
				}
			}
			else 
			{
				ListPopTail(list, (void**)&left);
				node = CreateUniaryNode(left,((Node*)pValue)->m_data.m_uni);
				if(node == NULL)
				{
					return NULL;
				}
			}
		}
		else 
		{
			node = CreateVariableNode(_string);
			if(node == NULL)
			{
				return NULL;
			}
		}
		ListPushTail(list, node);
		strtok(NULL, " ");
	}
	return node;
}



static double Add(double _num1, double _num2)
{
	return _num1+_num2;
}

static double Sub(double _num1, double _num2)
{
	return _num1 - _num2;
}

static double Mul(double _num1, double _num2)
{
	return _num1 * _num2;
}

static double Div(double _num1, double _num2)
{
	if(_num2 == 0)
	{
		return 0;
	}
	return _num1 / _num2;
}

static double Pow(double _num1, double _num2)
{
	return _num1^_num2;
}

static void AddFunc(HashMap* _map)
{
	int i, size = 0;
	Function* func;
	BinFunc bin[] = {Add, Sub, Mul, Div, Pow};
	char* operators[] = {"+", "-", "*", "/", "^"};
	
	size = sizeof(operators)/sizeof(operators[0]);
	for(i = 0; i < size; i++)
	{
		func = (Function*)malloc(sizeof(Function));
		if(func != NULL)
		{
			return;
		}
		func->m_funcFlag = BINARY_OP;
		func->m_func.m_binFunc = bin[i];	
		if((HashMap_Insert(_map, operators[i], func)) != MAP_SUCCESS)
		{
			return;
		}
	}
}

static double CalcRec(Exp* _ep, Node* _root)
{
	void* pValue;
	switch(_root->m_type)
	{
		case VALUE:
			return _root->m_data.m_value;
		case BINARY_OP:
			return (_root->m_data.m_bin(CalcRec(_ep, _root->m_left), CalcRec(_ep, _root->m_right)));
		case UNARY_OP:
			return (_root->m_data.m_uni(CalcRec(_ep, _root->m_left)));
		case VARIABLE:
			HashMap_Find(_ep->m_var, _root->m_data.name, &pValue);
			return *(double*)pValue;
	}
	return 0;
}

static int keysEqualFunc(const void* _firstKey, const void* _secondKey)
{
	if(_firstKey == NULL || _secondKey == NULL)
	{
		return NULL_ERROR;
	}
	if(*(char*)_firstKey == *(char*)_secondKey)
	{
		return TRUE;
	}
	return FALSE;
}


static void KeyDestroy(void* _key)
{
	if(_key == NULL)
	{
		return;
	}
	free(_key);
}


static void FuncDestroy(void* _func)
{
	if(_func == NULL)
	{
		return;
	}
	free(_func);
}

static void ValDestroy(void* _value)
{
	if(_value == NULL)
	{
		return;
	}
	free(_value);
}
