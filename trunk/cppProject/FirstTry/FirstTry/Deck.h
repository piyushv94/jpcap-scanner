#ifndef _Deck
#define _Deck
#include<vector>
#include"Deck.h"
#include<cstdlib>
#include<algorithm>
#include<ctime>
//template<class C> Deck<C>& operator+=(C carte);
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
}
#endif