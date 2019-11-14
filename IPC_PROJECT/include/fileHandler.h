#ifndef __FILEHANDLER_H__
#define __FILEHANDLER_H__

#include "CDR.h"
#include "MSQ.h"
#define MSG_TYPE 1 
/*
 * @brief handler a file and send to the message Q.
 * @param[in] _fname - the file name.
 * @param[in] _id - the message Q id.
 * @param[in] _msgType - the message type for the message Q.
 * @return void.
 */
void fileHandler(const char* _fname, int _id, long _msgType);

#endif /*__FILEHANDLER_H__*/ 
