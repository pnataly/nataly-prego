#include "zlogc.h"



int main()
{
	int port=3;

	zlog_init("app.log.config");
	ZLOG(LOG_WARNING,"message 1",port);
	ZLOG(LOG_WARNING,"message 2",port);
	ZLOG(LOG_WARNING,"message 3",port);
	ZLOG(LOG_WARNING,"message 4",port);
	ZLOG(LOG_WARNING,"message 5",port);

	return 0;
}
