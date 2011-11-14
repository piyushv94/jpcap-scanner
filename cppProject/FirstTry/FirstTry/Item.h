
#ifndef _Item
#define _Item

#include<iostream>
using std::ostream;

class Item{
public:
	virtual ostream& print(ostream&) const = 0;
//	friend ostream& operator<<(ostream& ,Item &);
};


/*
ostream& operator<<(ostream& _os , Item & item){
	return item.print(_os);
}*/
#endif