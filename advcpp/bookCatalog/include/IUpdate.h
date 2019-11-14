#ifndef IUPDATE_H
#define IUPDATE_H

#include <tr1/memory>
#include "Book.h"

namespace advcpp{
using std::tr1::shared_ptr;

class IUpdate
{
	virtual void Update(shared_ptr<Book> book) = 0;
};

}

#endif /*IUPDATE_H*/ 
