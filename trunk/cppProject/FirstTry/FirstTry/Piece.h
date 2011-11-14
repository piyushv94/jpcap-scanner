#ifndef _Piece
#define _Piece


#include "Item.h"


class Piece:public Item{
public:
	ostream& print(ostream&) const ;
	friend ostream& operator<<(ostream& ,Piece &);
};

#endif