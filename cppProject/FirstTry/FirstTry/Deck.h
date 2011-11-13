#ifndef _Deck
#define _Deck
#include<vector>
using std::vector;
template<class C> class Deck{
	vector<C> cards;
public:
	C draw();
	Deck<C>& operator+=(C carte);
}
#endif