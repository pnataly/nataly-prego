#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "commons.h"

//Thread exception

class Thread_Create_Failure_Exception : public std::exception 
{
public:
	Thread_Create_Failure_Exception(int res) 
	:	m_err(res) 
	{}
	
	int What() const
	{
		return m_err;
	}
private:
	int m_err;
};

//Mutex exceptions

class Mutex_Create_Failure_Exception : public std::exception 
{
public:
	Mutex_Create_Failure_Exception(int res) 
	:	m_err(res) 
	{}
	
	const int What() const
	{
		return m_err;
	}
private:
	int m_err;
};


class Mutex_Lock_Unrecavoble_Exception : public std::exception 
{
public:
	Mutex_Lock_Unrecavoble_Exception(int res) 
	:	m_err(res) 
	{}
	
	const int What() const
	{
		return m_err;
	}
private:
	int m_err;
};

class Mutex_UnLock_Failure_Exception : public std::exception 
{
public:
	Mutex_UnLock_Failure_Exception(int res) 
	:	m_err(res) 
	{}
	
	const int What() const
	{
		return m_err;
	}
private:
	int m_err;
};

//condition variable exception

class CondVar_Create_Failure_Exception : public std::exception 
{
public:
	CondVar_Create_Failure_Exception(int res) 
	:	m_err(res) 
	{}
	
	const int What() const
	{
		return m_err;
	}
private:
	int m_err;
};


class CondVar_Wait_Failure_Exception : public std::exception 
{
public:
	CondVar_Wait_Failure_Exception(int res) 
	:	m_err(res) 
	{}
	
	const int What() const
	{
		return m_err;
	}
private:
	int m_err;
};

class CondVar_Signal_Failure_Exception : public std::exception 
{
public:
	CondVar_Signal_Failure_Exception(int res) 
	:	m_err(res) 
	{}
	
	const int What() const
	{
		return m_err;
	}
private:
	int m_err;
};

class CondVar_Broadcast_Failure_Exception : public std::exception 
{
public:
	CondVar_Broadcast_Failure_Exception(int res) 
	:	m_err(res) 
	{}
	
	const int What() const
	{
		return m_err;
	}
private:
	int m_err;
};

#endif /*EXCEPTIONS_H*/ 

