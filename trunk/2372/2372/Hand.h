#ifndef _myHand
#define _myHand
#include<iostream>
#include<vector>
#include<algorithm>
#include"Deck.h"
using std::vector;
using std::ostream;
template <class C>class Hand{
	vector<C> cards;
	friend ostream& operator<<(ostream &_os,const Hand<C>& _h);
public:
	Hand<C>& operator+=(const C& carte){
		cards.push_back(carte);
	}
	C& operator[](int index){
		return cards[index];
	}
	C play(int index){
		C res=cards[index];
		std::swap(cards.begin()+index,cards.end()-1);
		cards.pop_back();
		return res;
	}
	void exchangeCards(Deck<C>& jeu){
		vector<C> temp;
		for(int i=5;i>0;i--){
			temp[i]=jeu.draw();
		}
		for(int i=5;i>0;i--){
			jeu+=play(i);
		}
		cards=temp;
	}
};
template<class C>ostream& operator<<(ostream &_os,const Hand<C>& _h){
		for(int i=0;i<5;i++)
			_os<<_h.cards[i]<<" ";
	}
#endif