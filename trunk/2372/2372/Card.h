#ifndef _myCard
#define _myCard
#include<iostream>
using std::ostream;
enum Direction{WEST=0,SOUTH=1,NORTH=2,EAST=3};
class Card{
	friend ostream& operator<<(ostream &_os,const Card& _c);
public:
	int distance;
	Direction direction;
	Card(const Direction&,const int&);
	Card();
	int getDistance() const;
	Direction getDirection() const;
	void unitTest();
};
#endif