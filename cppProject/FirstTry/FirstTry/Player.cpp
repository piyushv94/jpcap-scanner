/*[4 points] Design a class Player with the following methods:
string getName() const: returns the name of the player.
char getInitial( char x ) const: returns the first letter of the name of the player which is not x. It will throw an exception illegalName if no such letter in the player's name exists.
Hand<Card>& getHand(): return the hand of the player.
Piece& removePiece(): Removes a piece from this player's home. It will throw an exception noPiece if the no piece is left.
void addPiece(Piece& piece): Increases the count of pieces in this player's home by one.
int increaseBlocks( int i ): Increases the count of blocks for this player returns the number of blocks after the operation.
bool decreaseBlocks( int i ): Decreases the count of blocks for this player returns true if the player had enough blocks for the operation.
int increaseBlocks( int i ): Increases the count of blocks for this player returns the number of blocks after the operation.
int increasePoints( int i ): Increases the points for this player and returns the players points.
A player must also be printable with the insertion operator cout << hand; (see above for an example printout).*/
#include"Player.h"
#include"myException.h"
#include<string>
using std::string;
string Player::getName() const{
	return Name;
}
char Player::getInitial(char x) const{
	int index=Name.find_first_not_of(x);
	if (index==string::npos)
	{
		throw myException("illegalName");
	}
	return Name[index];
}
Hand<Card>& Player::getHand(){
	return myHand;
}