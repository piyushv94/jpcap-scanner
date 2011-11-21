#ifndef _myGameBoard
#define _myGameBoard
#include"Tower.h"
#include"Piece.h"
#include"Player.h"
#include"Card.h"
#include"Deck.h"
#include"BoardPosition.h"
#include"Item.h"
#include"Hand.h"
#include"myException.h"
class GameBoard{
	Item myItem[9][9];
	Deck<Card> myDeck;
	friend ostream& operator<<(ostream &_os,const GameBoard& _gb);
public:
	GameBoard();
	bool isValidMove(const Player& p, const Card& c, const BoardPosition& bp) const;
	void move(Player& p, const Card& c, const BoardPosition& bp);
	void buildTower(Player& p, const Card& c, const BoardPosition& bp,int phase);
	void demolishTower(Player& p, const Card& c, const Card& pay, const BoardPosition& bp,int phase);
	void knockOffPiece(Player& p, const Card& c, const BoardPosition& bp);
	void unitTest();
};
#endif