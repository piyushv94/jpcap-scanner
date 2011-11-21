#ifndef _myPiece
#define _myPiece
#include"Item.h"
class Piece:public Item{
	char Name;
public:
	Piece(const char&);
	char getName() const;
	ostream& printOut(ostream& os,const Item& i) const;
	void unitTest();
};
#endif