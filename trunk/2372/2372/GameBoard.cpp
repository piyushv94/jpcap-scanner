#include"GameBoard.h"
#include<iostream>
using std::ostream;
using std::endl;
GameBoard::GameBoard(Deck<Card>& temp){
	myDeck=temp;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			myItem[i][j]=new Tower(0);
	myItem[0][0]=new Tower(3);myItem[0][2]=new Tower(1);myItem[0][6]=new Tower(1);myItem[0][8]=new Tower(3);
	myItem[1][3]=new Tower(1);
	myItem[2][2]=new Tower(1);myItem[2][4]=new Tower(2);myItem[2][7]=new Tower(2);
	myItem[3][0]=new Tower(1);myItem[3][5]=new Tower(1);myItem[3][8]=new Tower(1);
	myItem[4][2]=new Tower(2);myItem[4][4]=new Tower(4);myItem[4][6]=new Tower(2);myItem[4][2]=new Tower(1);
	myItem[5][1]=new Tower(1);myItem[5][8]=new Tower(1);
	myItem[6][4]=new Tower(2);myItem[6][6]=new Tower(1);
	myItem[7][2]=new Tower(2);myItem[7][5]=new Tower(1);
	myItem[8][0]=new Tower(3);myItem[8][3]=new Tower(1);myItem[8][8]=new Tower(3);
	//bebug
};GameBoard::GameBoard(){
	myDeck=Deck<Card>();
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			myItem[i][j]=new Tower(0,i,j);
	myItem[0][0]=new Tower(3);myItem[0][2]=new Tower(1);myItem[0][6]=new Tower(1);myItem[0][8]=new Tower(3);
	myItem[1][3]=new Tower(1);
	myItem[2][2]=new Tower(1);myItem[2][4]=new Tower(2);myItem[2][7]=new Tower(2);
	myItem[3][0]=new Tower(1);myItem[3][5]=new Tower(1);myItem[3][8]=new Tower(1);
	myItem[4][2]=new Tower(2);myItem[4][4]=new Tower(4);myItem[4][6]=new Tower(2);myItem[4][2]=new Tower(1);
	myItem[5][1]=new Tower(1);myItem[5][8]=new Tower(1);
	myItem[6][4]=new Tower(2);myItem[6][6]=new Tower(1);
	myItem[7][2]=new Tower(2);myItem[7][5]=new Tower(1);
	myItem[8][0]=new Tower(3);myItem[8][3]=new Tower(1);myItem[8][8]=new Tower(3);
	
};
GameBoard::GameBoard(Player &a,Player &b){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			myItem[i][j]=new Tower(0);
	myItem[0][0]=new Tower(3);myItem[0][2]=new Tower(1);myItem[0][6]=new Tower(1);myItem[0][8]=new Tower(3);
	myItem[1][3]=new Tower(1);
	myItem[2][2]=new Tower(1);myItem[2][4]=new Tower(2);myItem[2][7]=new Tower(2);
	myItem[3][0]=new Tower(1);myItem[3][5]=new Tower(1);myItem[3][8]=new Tower(1);
	myItem[4][2]=new Tower(2);myItem[4][4]=new Tower(4);myItem[4][6]=new Tower(2);myItem[4][2]=new Tower(1);
	myItem[5][1]=new Tower(1);myItem[5][8]=new Tower(1);
	myItem[6][4]=new Tower(2);myItem[6][6]=new Tower(1);
	myItem[7][2]=new Tower(2);myItem[7][5]=new Tower(1);
	myItem[8][0]=new Tower(3);myItem[8][3]=new Tower(1);myItem[8][8]=new Tower(3);
	
};
	bool GameBoard::isValidMove(const Player& p, const Card& c, const BoardPosition& bp) const{
		bool res=true;
		int x=bp.x;
		int y=bp.y;
		/*A player can move one of the player's pieces on the board through 
		playing the corresponding card. Pieces can never move through towers or opponent's pieces.*/
		Direction d=c.getDirection();
		int dis=c.getDistance();
		switch(d){
			case WEST:
				for(int i=1;i<=dis;i++)
				{
					if(y-i<=0){
						res=false;
						break;
					}
					if((((Tower*)(myItem[x][y-i]))->getBlocks()!=0)){
						if((((Piece*)(myItem[x][y-i]))->getName()!=p.getInitial(' '))){
							res=false;
							break;
						}
					}
				}
				break;
			case EAST:
				for(int i=1;i<=dis;i++)
				{
					if(bp.y+i>8){
						res=false;
						break;
					}
					if((((Tower*)(myItem[x][y+i]))->getBlocks()!=0)){
						if((((Piece*)(myItem[x][y+i]))->getName()!=p.getInitial(' '))){
						res=false;
						break;
					}
					}
					
				}
				break;
				case NORTH:
				for(int i=1;i<=dis;i++)
				{
					if(x-i<=0){
						res=false;
						break;
					}
					if((((Tower*)(myItem[x-i][y]))->getBlocks()!=0)){
						if((((Piece*)(myItem[x-i][y]))->getName()!=p.getInitial(' '))){
						res=false;
						break;
					}
					}
					
				}
				break;
				case SOUTH:
				for(int i=1;i<=dis;i++)
				{
					if(x+i>8){
						res=false;
						break;
					}
					if((((Tower*)(myItem[x+i][y]))->getBlocks()!=0)){
						if((((Piece*)(myItem[x+i][y]))->getName()!=p.getInitial(' '))){
						res=false;
						break;
					}
					}
					
				}
				break;
		}
		return res;
	};
	void GameBoard::move(Player& p, const Card& c, const BoardPosition& bp){
		if(isValidMove(p,c,bp))
		{
			int x=bp.x;
			int y=bp.y;
			if(c.getDirection()==NORTH)
			{x-=c.getDistance();}
			else if(c.getDirection()==SOUTH)
			{x+=c.getDistance();}
			else if(c.getDirection()==WEST)
			{y-=c.getDistance();}
			else if(c.getDirection()==EAST)
			{y+=c.getDistance();}
			if((((Tower*)(myItem[x][y]))->getBlocks()!=0)&&(x!=bp.x&&y!=bp.y))
						throw myException("illegalMove");
			if(bp.x!=x||bp.y!=y){
			myItem[x][y]=myItem[bp.x][bp.y];
			myItem[bp.x][bp.y]=new Tower(0);}
		}
		else
			throw myException("illegalMove");
	};
	void GameBoard::buildTower(Player& p, const Card& c, const BoardPosition& bp,int phase){
		/*A player can build a tower at the current location of one of the player's pieces. 
		For building a tower, the player needs to play a cards with a number according to 
		the height of the tower and have enough blocks to build the tower. 
		The height of the tower is controlled by the phase of the game. 
		The player receives points corresponding to the number of blocks of the tower. 
		The player's piece is returned to the player's side of the board 
		(and can be re-added to the board in a future turn).
		pays with the action card c for a tower to be build by the player on board position bp. 
		It will throw an exception illegalBuild if the tower cannot be built (invalid). 
		It must update a Player because of the construction.*/
		int x=bp.x;
		int y=bp.y;
		if((((Piece*)myItem[x][y])->getName()==p.getInitial('x')))
		{
			if(p.increaseBlocks(0)>=phase&&c.getDistance()==phase+1)
			{
				p.decreaseBlocks(phase+1);
				p.increasePoints(phase+1);
				myItem[x][y]=new Tower(c);
				p.addPiece();
			}
			else
				throw myException("illegalBuild");
		}
		else
			throw myException("illegalBuild");
	};
	void GameBoard::demolishTower(Player& p, const Card& c, const Card& pay, const BoardPosition& bp,int phase){
		/*If a player moves a piece to the location of a current tower, 
		the tower is demolished by playing a card according to the height of the tower. 
		The player receives points corresponding to the number of blocks of the tower and the player receives the blocks of the tower. 
		However, if a player has currently seven or more blocks the player has to build a tower first before removing another tower. 
		A player can also not demolish a tower if the player does not have the required card to pay for it.*/
		/*pays with the action card pay for a tower to be demolished when moving a piece to the board position bp. 
		It will throw an exception illegalDemolish if the tower cannot be demolished (invalid). 
		It must update a Player because of the demolishing of the tower.*/
		Card temp=c;
		temp.distance--;
		if(!isValidMove(p,temp,bp))
			throw myException("illegalDemolish");
		if(p.increaseBlocks(0)>=7)
			throw myException("illegalDemolish");
		else if(pay.getDistance()!=phase)
			throw myException("illegalDemolish");
		else{
				int x=bp.x;
				int y=bp.y;
				if(c.getDirection()==NORTH)
				{x-=c.getDistance();}
				else if(c.getDirection()==SOUTH)
				{x+=c.getDistance();}
				else if(c.getDirection()==WEST)
				{y-=c.getDistance();}
				else if(c.getDirection()==EAST)
				{y+=c.getDistance();}
				if((((Tower*)(myItem[x][y]))->getBlocks()==phase)){
				p.increasePoints(phase);
				p.increaseBlocks(phase);
				Hand<Card> tempC=p.getHand();
				delete(myItem[bp.x][bp.y]);
				if(x!=bp.x&&y!=bp.y)
				delete(myItem[x][y]);
				myItem[x][y]=new Tower(0);
				myItem[bp.x][bp.y]=new Tower(0);
				p.addPiece();
				}
				else
					throw myException("illegalDemolish");
		}
	};
	void GameBoard::knockOffPiece(Player& p, const Card& c, const BoardPosition& bp){
		Card temp=c;
		temp.distance--;
		if(!isValidMove(p,temp,bp))
			throw myException("illegalKnockOff");
		else{
				int x=bp.x;
				int y=bp.y;
 				if(c.getDirection()==NORTH)
				{x-=c.getDistance();}
				else if(c.getDirection()==SOUTH)
				{x+=c.getDistance();}
				else if(c.getDirection()==WEST)
				{y-=c.getDistance();}
				else if(c.getDirection()==EAST)
				{y+=c.getDistance();}
				if((((Piece*)(myItem[x][y]))->getName()==p.getInitial('x'))){
					throw myException("illegalKnockOff");}
				if((((Tower*)(myItem[x][y]))->getBlocks()>=0)){
					throw myException("illegalKnockOff");}
				myItem[bp.x][bp.y]=new Tower(0);
				myItem[x][y]=new Piece(p.getInitial('x'));
				p.increasePoints(1);
		}
	};
	void GameBoard::unitTest(){};
	ostream& operator<<(ostream &_os,const GameBoard& _gb){
		_os<<"             "<<"NORTH"<<std::endl;
		_os<<"       ";
		for(int i=1;i<=9;i++)
			_os<<i<<" ";
		_os<<std::endl;
		for(int i=0;i<9;i++){
			if(i==4)
				_os<<"WEST ";
			else
				_os<<"     ";
			char temp='a';
			temp+=i;
			_os<<temp<<" ";
			for(int j=0;j<9;j++){
				Item* _i=_gb.myItem[i][j];
				_os<<*_i<<" ";}
			if(i==4)
				_os<<"EAST";
			_os<<std::endl;
		}
		_os<<"             SOUTH"<<std::endl;
		return _os;
	}