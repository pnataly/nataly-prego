#ifndef __BORROWER_T_H__
#define __BORROWER_T_H__

#include <string>
using namespace std;


class Borrower_t
{
	public:
		Borrower_t();
		Borrower_t(string _name, long _phoneNum, size_t _id);
		Borrower_t(const Borrower_t& bt);
		~Borrower_t();
		
		Borrower_t& operator=(const Borrower_t& bt);
		const string& GetName() const;
		const long long& GetPhoneNum() const;
		const size_t& GetId() const;
	
	private:
		const string m_name;
		const size_t m_id;
		long long m_phoneNum;
};



#endif /*__BORROWER_T_H__*/ 
