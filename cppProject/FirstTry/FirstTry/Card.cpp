#include"Card.h"

ostream& operator<<(ostream &_os,const Card& _c){
	switch(_c.direction){
		case EAST:_os<<"E";break;
		case SOUTH:_os<<"S";break;
		case WEST:_os<<"W";break;
		case NORTH:_os<<"N";break;
	}
	_os<<_c.distance;
	return _os;
};