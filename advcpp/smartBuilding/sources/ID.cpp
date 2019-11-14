#include "ID.h"

namespace smarthome{

ID::ID(const string& id)
:	m_id(id)
{}

const string& ID::GetId() const
{
	return m_id;
}

}
