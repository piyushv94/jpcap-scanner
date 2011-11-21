#ifndef _myDeck
#define _myDeck
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using std::vector;
template<class C> class Deck{
	vector<C> cards;
public:
	C draw(){
		C res;
		int index=srand((unsigned)time(0))%64;
		res=cards[index];
		std::swap(cards.begin()+index,cards.end()-1);
		cards.pop_back();
		return res;
	}
	Deck<C>& operator+=(C carte){
		cards.push_back(carte);
	}
};
#endif