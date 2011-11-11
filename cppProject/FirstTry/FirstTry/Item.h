#include <iostream>
using std::ostream;

class Item{
public:
	 friend ostream& operator<<(ostream& ,const Item &);
};