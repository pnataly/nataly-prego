#ifndef __EXCEPTION_T_H__
#define __EXCEPTION_T_H__

#include <string>
using namespace std;

template <class T> class TException_t
{
	friend ostream& operator<< (ostream& os, const TException_t& _ex)  //left shift operator
	{
		os << "The file name: " << _ex.m_file << endl;
		os << "The line number: " << _ex.m_line << endl;
		os << "The description: " << _ex.m_description << endl;
		os << "The data: " << _ex.m_data << endl;
		return os;
	}

	public: 
		TException_t(const T& _data, const string& _file , const int& _line, const string& _des = "")  //CTOR
		{
			m_data = _data;
			m_file = _file;
			m_line = _line;
			m_description = _des;
		}
		 
		TException_t(const TException_t& _ex)  //copy CTOR
		{
			m_file = _ex.m_file;
			m_line = _ex.m_line;
			m_description = _ex.m_description;
			m_data = _ex.m_data;
		}
		
		~TException_t() {};  //DTOR
	
		TException_t& operator= (const TException_t& _ex) //assignment operator
		{
			if(this != &_ex)
			{
				m_data = _ex.m_data;
				m_file = _ex.m_file;
				m_line = _ex.m_line;
				m_description = _ex.m_description;
			}
			return *this;
		}
		
		const T& GetData() const {return m_data;}
		const string& GetFile() const {return m_file;}
		const int& GetLine() const {return m_line;}
		const string& GetDescription() const {return m_description;}
		
	private:
		T m_data;
		string m_file;
		int m_line;
		string m_description;
};


#endif /*__EXCEPTION_T_H__*/
 
