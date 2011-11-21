#include"Card.h"
#include<iostream>
Card::Card(const Direction& d,const int& dis){
	direction=d;
	distance=dis;
};
int Card::getDistance()const{
	return distance;
};
Direction Card::getDirection()const{
	return direction;
};
void Card::unitTest(){
	std::cout<<"Card Test:"<<std::endl;
	std::cout<<(Card)*this;
	std::cout<<std::endl;
};
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