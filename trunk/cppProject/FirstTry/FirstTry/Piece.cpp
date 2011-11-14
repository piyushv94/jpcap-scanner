#include"Piece.h"



ostream& Piece::print(ostream& _os) const{
	_os<<"piece";
	return _os;
}

ostream& operator<<(ostream& _os,Piece& piece){
	return piece.print(_os);
}