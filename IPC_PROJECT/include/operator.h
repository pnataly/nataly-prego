#ifndef __OPERATOR_H__
#define __OPERATOR_H__
#define IN 1
#define OUT 2

typedef struct Operator Operator;

/*
 * @brief: Create a new operator.
 * @return: pointer to the created operator.
 */
Operator* CreateOperator();

/*
 * @brief: destroy the operator.
 * @param[in]: _opr : the operator to be destroyed.
 * @return: void.
 */
void DestroyOperator(Operator** _opr);

/*
 * @brief: set the key of the operator.
 * @param[in]: _opr : the operator.
 * @param[in]: _key : the key to set.
 * @return: void.
 */
void SetOprKey(Operator* _opr, size_t _key);

/*
 * @brief: set the call data of the operator.
 * @param[in]: _opr : the operator.
 * @param[in]: _flag : IN/OUT.
 * @param[in]: _duration : the duration of the call.
 * @return: void.
 */
void SetOprCall(Operator* _opr, int _flag, size_t _duration);

/*
 * @brief: set the SMS data of the operator.
 * @param[in]: _opr : the operator.
 * @param[in]: _flag : IN/OUT.
 * @return: void.
 */
void SetOprSMS(Operator* _opr, int _flag);

/*
 * @brief: copy the data of the operator.
 * @param[in]: _opr - the operator to copy.
 * @return: pointer to the new operator.
 */
Operator* CopyOpr(Operator* _opr);

/*
 * @brief: print the data of the operator.
 * @param[in]: _opr - the operator.
 * @return: void.
 */
void PrintOpr(Operator* _opr);


#endif /*__OPERATOR_H__*/ 
