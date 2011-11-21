#include"Piece.h"
#include<iostream>
using std::ostream;
Piece::Piece(const char& name){
	Name=name;
};
char Piece::getName()const{
	return Name;
};
ostream& Piece::printOut(ostream& os,const Item& i) const{
	os<<((Piece)*this).Name;
	return os;
};
void Piece::unitTest(){
	std::cout<<"Piece Test"<<std::endl;
	std::cout<<(Piece)*this;
	std::cout<<std::endl;
};