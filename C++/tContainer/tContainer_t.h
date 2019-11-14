#ifndef __TCONTAINER_T_H__
#define __TCONTAINER_T_H__

#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;

template<class T, template <class Tval, class = std::allocator <Tval*> > class Container> 
class tContainer_t
//template <class T, class Container> class tContainer_t
{
	typedef typename Container<T*>::iterator iter_t;
	typedef typename Container<T*>::const_iterator citer_t;
	
	public:
		tContainer_t(){}	//default CTOR
		~tContainer_t(){}	//DTOR
		
		bool IsEmpty() const {return m_container.empty();}
		const size_t NumOfElem() const {return m_container.size();}
		
		void Insert(const T* _data) {m_container.insert(m_container.end(), (T*)_data);} 	
		
		const T* GetFirstElem() const {return *(m_container.begin());}
		const T* GetLastElem() const {return *(m_container.rbegin());}
		const T* FindElem(const T& _param) const 
		{
			return *find_if(m_container.begin(), m_container.end(), predicate(_param));
		} 

		const T* RemoveElem(const T& _val)
		{
			iter_t it = find_if(m_container.begin(), m_container.end(), predicate(_val));
			return (it == m_container.end() ? 0 : *remove(m_container.begin(), m_container.end(), (const T&) _val));
		}
		
		void DeleteElem(const T& _val) 
		{
			iter_t it = find_if(m_container.begin(), m_container.end(), predicate(_val));
			m_container.erase(it);
		}
		void DeleteAll(){m_container.erase(m_container.begin(), m_container.end());}  
		void RemoveAll(){m_container.clear();}
	
		const T* operator[](size_t _index) const //throw exception
		{
			try
			{
				if(_index > m_container.size())
				{
					throw _index;
				}
			}
			catch(size_t _index)
			{
				return NULL;
			}
			if(typeid(Container) == typeid(vector<T*>))
			{
				return (*(vector<T*>*)&m_container)[_index];
			}
			citer_t it = m_container.begin();
			advance(it, _index);
			return *it;
		}
		
	private:
		tContainer_t(const tContainer_t& ct);
		tContainer_t& operator= (const tContainer_t& ct);
		Container m_container;
		
		class predicate
		{
			public:
				predicate(const T& _val):m_val(_val){}
				bool operator()(const T* _param) const {return *_param == m_val;}
				
			private:
				T m_val;
		};
};



#endif /*__TCONTAINER_T_H__*/

