#ifndef _myTower
#define _myTower
#include"Item.h"
#include"Card.h"
#include"myException.h"
using std::ostream;
class Tower:public Item{
	int numBlocks;
public:
	Tower(int val=0,int x=0,int y=0);
	Tower(const Card& carte);
	int getBlocks() const;
	ostream& printOut(ostream& os,const Item& i) const;
	int demolish(Card carte) const;
	void unitTest();
};
#endif