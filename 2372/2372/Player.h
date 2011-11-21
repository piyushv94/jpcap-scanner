#ifndef _myPlayer
#define _myPlayer
#include"Hand.h"
#include"Card.h"
#include"Piece.h"
#include"Hand.h"
#include<string>
#include<iostream>
using std::ostream;
using std::string;

class Player{
	string Name;
	Hand<Card> myHand;
	Piece *myPiece;
	int Blocks;
	int point;
	int countPiece;
	friend ostream& operator<<(ostream&,const Player &);
public:
	string getName() const;
	char getInitial( char x ) const;
	Hand<Card>& getHand();
	Piece& removePiece();
	void addPiece();
	int increaseBlocks( int i );
	bool decreaseBlocks( int i );
	int increasePoints( int i );
};
#endif