enum Action{EXCHANGE, BUILD, DEMOLISH, ADD, KNOCKOFF, MOVE};
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
Action askPlayer(Player& currentPlayer,BoardPosition& bp,Card& c);
Card askHowToPay( Player& p );