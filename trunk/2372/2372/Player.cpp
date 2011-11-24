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
Player::Player(string &s){
	Name=s;
	Blocks=0;
	point=0;
	countPiece=0;
}
Player::Player(){
	Name=" ";
	Blocks=0;
	point=0;
	countPiece=0;
}
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
Piece& Player::removePiece(){
	if(countPiece==0)
		throw myException("no piece");
	countPiece--;
	myPiece=new Piece(getInitial('X'));
	return *myPiece;
}
void Player::addPiece(){
	countPiece++;
}
int Player::increaseBlocks( int i ){
	Blocks+=i;
	return Blocks;
}
bool Player::decreaseBlocks( int i ){
	bool res=true;
	if(Blocks-i<0)
		res=false;
	else
		Blocks-=i;
	return res;
}
int Player::increasePoints( int i ){
	return point+=i;
}
ostream& operator<<(ostream& os,const Player &p){
	os<<"       Player "<<p.getInitial('X')<<": "<<p.point<<" pts"<<std::endl;
	os<<"Blocks: "<<p.Blocks;
	Hand<Card>temp=p.myHand;
	os<<" Cards: "<<temp;
	os<<" Piece: ";
	for(int i=0;i<p.countPiece;i++)
		os<<p.getInitial('X')<<" ";
	os<<std::endl;
	return os;
}