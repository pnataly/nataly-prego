#ifndef __SUBSCRIBER_H__
#define __SUBSCRIBER_H__
#define IN 1
#define OUT 2

typedef struct Subscriber Subscriber;


/*
 * @brief: Create a new subscriber.
 * @return: pointer to the created subscriber.
 */
Subscriber* CreateSubscriber();

/*
 * @brief: destroy the subscriber.
 * @param[in]: _sub : the subscriber to be destroyed.
 * @return: void.
 */
void DestroySubscriber(Subscriber** _sub);

/*
 * @brief: set the key of the subscriber.
 * @param[in]: _sub : the subscriber to be destroyed.
 * @param[in]: _key : the key to set.
 * @return: void.
 */
void SetSubKey(Subscriber* _sub, size_t _key);

/*
 * @brief: set the internet data of the subscriber.
 * @param[in]: _sub : the subscriber to be destroyed.
 * @param[in]: _down : MB download data.
 * @param[in]: _up : MB upload data.
 * @return: void.
 */
void SetInternet(Subscriber* _sub, size_t _down, size_t _up);

/*
 * @brief: set the SMS data of the subscriber.
 * @param[in]: _sub : the subscriber
 * @param[in]: _type : sent/recieve.
 * @param[in]: _flag : IN/OUT.
 * @return: void.
 */
void SetSubSMS(Subscriber* _sub, int _type, int _flag);

/*
 * @brief: set the call data of the subscriber.
 * @param[in]: _sub : the subscriber.
 * @param[in]: _type : sent/recieve.
 * @param[in]: _flag : IN/OUT.
 * @param[in]: _duration : the duration of the call.
 * @return: void.
 */
void SetSubCall(Subscriber* _sub, int _type, int _flag, size_t _duration);

/*
 * @brief: copy the data of the subscriber.
 * @param[in]: _sub : the subscriber to copy.
 * @return: pointer to the new subscriber.
 */
Subscriber* CopySub(Subscriber* _sub);

/*
 * @brief: print the data of the subscriber.
 * @param[in]: _sub : the subscriber.
 * @return: void.
 */
void PrintSub(Subscriber* _sub);


#endif /*__SUBSCRIBER_H__*/ 

