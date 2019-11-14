#include "Type.h"

namespace smarthome{

Type::Type(const string& type)
:	m_type(type)
{}

const string& Type::GetType() const
{
	return m_type;
}

}
