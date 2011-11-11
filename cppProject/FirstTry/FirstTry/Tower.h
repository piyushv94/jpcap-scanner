#include "Piece.h"

class Tower:public Item{
public:
	friend ostream& operator<<(ostream& ,const Tower &);
};