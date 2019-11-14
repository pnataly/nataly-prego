#ifndef __MSQ_H__
#define __MSQ_H__

#include "CDR.h"

/*
 * @brief Create a message Q.
 * @param[in] _filePath - the file path to create a MSQ key.
 * @return the MSQ id.
 */
int CreateMessageQ(char* _filePath);

/*
 * @brief destroy the message Q.
 * @param[in] _id : the message Q id.
 * @return: void.
 */
void MessageQDestroy(int _id);

/*
 * @brief read message from the message Q.
 * @param[in] msgid - the message Q id to read from.
 * @return CDR.
 */
void* ReadMessage(int msgid, size_t _size, long _msgType);

/*
 * @brief send message to the message Q.
 * @param[in] msgid - the message Q id to send to.
 * @return void.
 */
void SendMessage(int msgid, void* _item, size_t _size, long _msgType);

#endif /*__MSQ_H__*/ 
