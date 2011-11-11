#include "Item.h"

class Piece:public Item{
public:
	friend ostream& operator<<(ostream& ,const Piece &);
};

