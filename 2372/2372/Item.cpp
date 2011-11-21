#include"Item.h"
#include<iostream>
Item::Item(int a,int b){
	x=a;
	y=b;
}
int Item::getX()const{
	return x;
};
int Item::getY() const{
	return y;
};
void Item::unitTest(){
	std::cout<<"Item Test:"<<std::endl;
	std::cout<<(Item)*this;
	std::cout<<std::endl;
};
ostream& Item::printOut(ostream& os,const Item& i) const{ 
	os<<i.getX()<<','<<i.getY(); 
    return   os; 
}
ostream& operator<<(ostream& _os,const Item& _i){
	_i.printOut(_os,_i);
	return _os;
};