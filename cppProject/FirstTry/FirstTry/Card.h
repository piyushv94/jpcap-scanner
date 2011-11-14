#ifndef _Card
#define _Card

#include <iostream>
#include <string>
using std::ostream;
using std::string;


enum Direction {EAST, SOUTH, WEST, NORTH}; 
class Card{
	Direction direction;
	double distance;

public:
	Card(const Direction _direction = EAST,const double _distance = 0.0):direction(_direction),distance(_distance){
	}
	friend ostream& operator<<(ostream&,const Card &);
	Direction getDirection();
	double getDistance();
	
};
#endif