#include "Tower.h"


ostream& Tower::print(ostream& _os) const{
	_os<<"Tower";
	return _os;
}

ostream& operator<<(ostream& _os,Tower& piece){
	return piece.print(_os);
}