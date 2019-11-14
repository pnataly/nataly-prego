#ifndef __CAR_T_H__
#define __CAR_T_H__

#include <string>
#include <iostream>
using namespace std;

class car_t
{
	public:
		car_t():m_id(s_id){s_id++;m_capacity = s_capacity;}								//default CTOR.
		car_t(size_t _capacity):m_id(s_id){s_id++; m_capacity = _capacity;}				//CTOR from size_t.
		car_t(const car_t& _car):m_id(s_id) {s_id++; m_capacity = _car.m_capacity;}		//copy CTOR.
		
		typedef enum GearType_e {automatic, standard} GearType_e;
		
		const size_t GetId() const {return m_id;}
		const string GetName()const {return m_name;}
		const GearType_e GetGearType() const {return m_gearType;}
		bool operator<(const car_t&_car) const {return m_capacity < _car.m_capacity;}
		bool Compare(const car_t&_car) const;	
		
		static size_t GetDefCapactiy() {return s_capacity;}
		const size_t GetCapacity() const {return m_capacity;}
 		
	protected:
		~car_t(){;}			//DTOR.
		static void SetDefCapactiy(size_t _capacity) {s_capacity = _capacity;}
		void SetGearType(GearType_e _type){m_gearType = _type;}
		void SetName(string _name) {m_name = _name;}
		
	private:
		car_t& operator=(const car_t& _car){}	
		static size_t s_id;
		static size_t s_capacity;
		const size_t m_id;
		string m_name;
		size_t m_capacity;
		GearType_e m_gearType;	
};




#endif /*__CAR_T_H__*/ 
