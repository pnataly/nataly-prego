#ifndef __ZLOGC_H__
#define __ZLOGC_H__

/** 
*  @file zlog4c.h
*  @brief A log can be a file or a stream where we can store log entries. 
*		  Log entry contains information that depicts an error message or a trace message. 
*		  A log entry is basically a record (terminated with a new line) containing a detailed information written into the log file. The 	*	      record contains information provided by the developer and information gathered automatically.Each entry has a given severity.If *		  the log entry severity is lower than the current log level it will be ignored.Otherwise it will be written to the log file.
		  log entry :

		 +- year
		 |   +- month              +- process id (getPID)
		 |   |  +- day             |      +- thread id(getThread)      
		 |   |  |                  |      |                 
		2019-1-22  22:43:20.244  40059  1299 I  test@user.c:9 my log: 1 
				    |                         |   |     |   |      +-- message w/ params
				    +- time                   |   |     |   +--- line number
				                              |   |     +- source file name
				                              |    +- function name   
				                              |  
				                              +- log level (first letter)  (severnece of the event)
*/





/*no debug, i.e release build*/
#ifdef NDEBUG
	#define ZLOG(userLevel,message,...)     																				  \
		{   					      																				          \
			(IsAboveLevel(userLevel)) ? PrintLogEntry(__FILE__,__FUNCTION__,__LINE__,userLevel,'R',message,__VA_ARGS__) : 0;  \
		}

/*with debug, i.e debug build*/																											
#else
	#define ZLOG(userLevel,message,...)     																				   \
		{   					      																				           \
			(IsAboveLevel(userLevel)) ? PrintLogEntry(__FILE__,__FUNCTION__,__LINE__,userLevel,'D',message,__VA_ARGS__) : 0;   \
		}
#endif



typedef enum LOG_LEVEL
{
	 LOG_TRACE,			/*Trace message usually very detailed*/
     LOG_DEBUG,			/*A message useful for debugging*/
     LOG_INFO,			/*Informative message*/
     LOG_WARNING,		/*Warning*/
     LOG_ERROR,			/*An error occurred*/
	 LOG_CRITICAL,		/*Critical error*/
     LOG_SEVERE,		/*Server error requiring immediate intervention*/
     LOG_FATAL,			/*Fatal error signaling an emergency*/ 
     LOG_NONE			/*Used only in configuration file*/
}LOG_LEVEL;	




/** 
 * @brief Create a new log file.
 * @param[in] _configFile : configuraion file in the following format : 
						    1. "Level = ERROR" : only log messages with equal or higher level will actually be saved to the log file.
							2. "File = log_base_directory/default_log_file_name": directory path specifying where all log files will be placed 
								and file name to be used for logging entries. (example: /var/log/dbServer/db.log)	 	
 * @return void.
 */
void zlog_init(const char* _configFile); 





#endif /* __ZLOGC_H__ */

