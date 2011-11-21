#ifndef _myCard
#define _myCard
#include<iostream>
using std::ostream;
enum Direction{WEST,SOUTH,NORTH,EAST};
class Card{
	Direction direction;
	int distance;
	friend ostream& operator<<(ostream &_os,const Card& _c);
public:
	Card(const Direction&,const int&);
	int getDistance() const;
	Direction getDirection() const;
	void unitTest();
};
#endif