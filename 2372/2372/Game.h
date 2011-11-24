#include"Action.h"
#include"BoardPosition.h"
#include"Card.h"
#include"Deck.h"
#include"GameBoard.h"
#include"Hand.h"
#include"Item.h"
#include"myException.h"
#include"Piece.h"
#include"Player.h"
#include"Tower.h"
class Game{
	/*reates the deck with the 64 action cards and the game board with initial placement of towers. 
	This class also creates the two players and hands them their five initial action cards from the deck*/
	Deck<Card> deck;
	Player player[2];
	Hand<Card> hand[2];
public:
	Game();
	void runGame();
};