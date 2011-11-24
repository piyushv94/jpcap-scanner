#include"Action.h"
#include<iostream>
using std::cout;
using std::endl;
const string output[6]={"EXCHANGE", "BUILD", "DEMOLISH", "ADD", "KNOCKOFF", "MOVE"};
Action askPlayer(Player& currentPlayer,BoardPosition& bp,Card& c){
	std::cout<<endl<<endl<<"Choose a Action:"<<endl;
	for(int i=0;i<6;i++)
		cout<<i+1<<":"<<output[i]<<endl;
	int act;
	std::cin>>act;
	act--;
	switch (act) {
			case EXCHANGE:
				cout<<output[act]<<":"<<endl;
				return EXCHANGE;
				break;
			case BUILD:
				cout<<output[act]<<":"<<endl;
				return BUILD;
				break;
			case DEMOLISH:
				cout<<output[act]<<":"<<endl;
				return DEMOLISH;
				break;
			case ADD:
				cout<<output[act]<<":"<<endl;
				return ADD;
				break;
			case KNOCKOFF:
				cout<<output[act]<<":"<<endl;
				return KNOCKOFF;
				break;
			case MOVE:
				cout<<output[act]<<":"<<endl;
				return MOVE;
				break;
		}
	return EXCHANGE;
};
Card askHowToPay( Player& p ){
	Card c;
	Hand<Card>& h = p.getHand();
	std::cout<<"Choose a card:"<<std::endl;
	for(int i=0;i<5;i++)
		cout<<i+1<<": "<<h[i]<<endl;
	int numP;
	std::cin>>numP;
	c=h[numP-1];
	return c;
};