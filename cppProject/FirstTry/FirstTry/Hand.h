#ifndef _Hand
#define _Hand
#include<iostream>
#include<vector>
#include<algorithm>
#include"Deck.h"
using std::vector;
using std::ostream;
template <class C>class Hand{
	vector<C> cards;
	friend ostream& operator<<(ostream &_os,const Hand& _h);
	ostream& operator<<(ostream &_os,const Hand& _h){
		for(int i=0;i<5;i++)
			_os<<cards[i]<<" ";
	}
public:
	/*Hand<C>& operator+=(const C& carte): adds a card to the hand. Throws an exception of type handful if the hand is already full.
C& operator[](int index): returns a reference to a card from the players hand.
C play(int index): removes a card from the hand by playing it.
void exchangeCards(Deck& jeu): Exchanges all the cards in the hand with new cards from the deck and returns the old cards to the deck.*/
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
}
#endif