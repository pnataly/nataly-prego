#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>
class Insert
{
public:
	Insert(vector<T>& vec);
	void insert();
	map<T, int>& GetMap();
	
private:
	map<T, int> m_map; 
	pair<typename map<T, int>::iterator, bool> res;
	vector<T>& m_vec;
	vector<int>::iterator it;
};

template <class T>
Insert<T>::Insert(vector<T>& vec)
:	m_vec(vec)
{}

template <class T>
void Insert<T>::insert()
{
	for(it = m_vec.begin(); it != m_vec.end(); ++it)
	{
		res = m_map.insert(pair<T,int>(*it, 1));
		
		//if already existed in map
		if (res.second == false) 
		{
			m_map.erase(*it);
			m_map.insert(pair<T,int>(*it, ++res.first->second));
		}
	}
}

template <class T>
map<T, int>& Insert<T>::GetMap()
{
	return m_map;
}



template <class T>
class Check
{
public:
	Check(const map<T, int>& map);
	T& check(vector<T>& vec);
	
private:
	map<T, int> m_map; 
}; 

template <class T>
Check<T>::Check(const map<T, int>& map)
:	m_map(map)
{}

template <class T>
T& Check<T>::check(vector<T>& vec)
{
	typename vector<T>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it)
	{
		if(m_map.find(*it)->second == 1)
		{
			break;
		}
	}
	return *it;
}



template<typename T>
T& FindFirstUnique(vector<T>& vec)
{
	Insert<T> map(vec);
	map.insert();
	
	Check<T> ck(map.GetMap());
	return ck.check(vec);
}


const static int SIZE = 10;
int main()
{
	int Arr[SIZE] = {10,9,10,42,3,5,6,2,6,9};
	vector<int> vec;
	for(int i =0 ; i<SIZE; ++i)
	{
		vec.push_back(Arr[i]);
	}
	cout << "The unique element: " << FindFirstUnique<int>(vec) << endl;
	return 0;
}



