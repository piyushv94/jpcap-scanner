#ifndef _myHand
#define _myHand
#include<iostream>
#include<vector>
#include<algorithm>
#include"Deck.h"
using std::vector;
using std::ostream;
template <class C>class Hand{
	template<class C>friend ostream& operator<<(ostream &_os,const Hand<C>& _h);
public:
	vector<C> cards;
	Hand<C>& operator+=(const C& carte){
		cards.push_back(carte);
		return (Hand<C>)*this;
	}
	C& operator[](int index){
		return cards[index];
	}
	C play(int index){
		C res=cards[index];
		cards[index]=cards[cards.size()-1];
		cards[cards.size()-1]=res;
		cards.pop_back();
		return res;
	}
	void exchangeCards(Deck<C>& jeu){
		vector<C> temp;
		for(int i=5;i>0;i--){
			temp.push_back(jeu.draw());
		}
		for(int i=4;i>=0;i--){
			jeu+=play(i);
		}
		cards=temp;
	}
};
template<class C>ostream& operator<< (ostream &_os,const Hand<C>& _h){
		for(int i=0;i<5;i++)
		{
			Card c=_h.cards[i];
			_os<<c<<" ";
		}
		return _os;
	};
#endif