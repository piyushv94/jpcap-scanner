#include"Card.h"
#include"Item.h"
#include"Piece.h"
#include"Tower.h"
int main(){
	Card c=Card(EAST,1);
	c.unitTest();
	Item i;
	i.unitTest();
	Piece p=Piece('A');
	p.unitTest();
	Tower t=Tower(c);
	t.unitTest();
	return 0;
}