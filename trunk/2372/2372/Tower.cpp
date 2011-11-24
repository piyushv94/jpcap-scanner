#include"Tower.h"
#include<iostream>
using std::ostream;
Tower::Tower(int val,int _x,int _y){
	numBlocks=val;
	x=_x;
	y=_y;
};
Tower::Tower(const Card& carte){
	numBlocks=carte.getDistance();
};
ostream& Tower::printOut(ostream& os,const Item& i) const{
	if(((Tower)*this).numBlocks!=0)
	os<<((Tower)*this).numBlocks;
	else
		os<<'.';
	return os;
};
int Tower::getBlocks() const{
		return numBlocks;
};
int Tower::demolish(Card carte) const{
	if(carte.getDistance()!=numBlocks)
		throw myException("wrong card");
	else{
		return numBlocks;
	}
};
void Tower::unitTest(){
	std::cout<<"Tower Test"<<std::endl;
	std::cout<<(Tower)*this;
	std::cout<<std::endl;
};