#ifndef _Tower
#define _Tower

#include "Item.h"


class Tower:public Item{
public:
	ostream& print(ostream&) const ;
	friend ostream& operator<<(ostream& ,Tower &);
};

#endif