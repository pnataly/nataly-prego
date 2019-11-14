#include <stdio.h>
#include <stdlib.h>
#include "CDR.h"
#include "fileMonitor.h"
#include "MSQ.h"

#define MSQ_FILE_PATH "../messageQ.txt"
#define MSG_TYPE 1


int main()
{
	int id;
	id = CreateMessageQ(MSQ_FILE_PATH);
	RunMonitor(id, MSG_TYPE);	
	return 0;
}


