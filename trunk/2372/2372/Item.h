#ifndef _myItem
#define _myItem
#include<iostream>
using std::ostream;
class Item{
	int x;
	int y;
	friend ostream& operator<<(ostream &_os,const Item& _i);
public:
	Item(int _x=0,int _y=0);
	int getX()const;
	int getY()const;
	virtual ostream& printOut(ostream& os,const Item& i) const;
	void unitTest();
};
#endif