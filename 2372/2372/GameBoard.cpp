#include"GameBoard.h"
GameBoard::GameBoard(){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			myItem[i][j]=Tower(0);
	myItem[0][0]=Tower(3);myItem[0][2]=Tower(1);myItem[0][6]=Tower(1);myItem[0][8]=Tower(3);
	myItem[1][3]=Tower(1);
	myItem[2][2]=Tower(1);myItem[2][4]=Tower(2);myItem[2][7]=Tower(2);
	myItem[3][0]=Tower(1);myItem[3][5]=Tower(1);myItem[3][8]=Tower(1);
	myItem[4][2]=Tower(2);myItem[4][4]=Tower(4);myItem[4][6]=Tower(2);myItem[4][2]=Tower(1);
	myItem[5][1]=Tower(1);myItem[5][8]=Tower(1);
	myItem[6][4]=Tower(2);myItem[6][6]=Tower(1);
	myItem[7][2]=Tower(2);myItem[7][5]=Tower(1);
	myItem[8][0]=Tower(3);myItem[8][3]=Tower(1);myItem[8][8]=Tower(3);
	
};
	bool GameBoard::isValidMove(const Player& p, const Card& c, const BoardPosition& bp) const{
		bool res=false;
		/*A player can move one of the player's pieces on the board through 
		playing the corresponding card. Pieces can never move through towers or opponent's pieces.*/
		Direction d=c.getDirection();
		int dis=c.getDistance();
		switch(d){
			case NORTH:
				for(int i=0;i<=dis;i++)
				{
					if(bp.y-i>=0){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x][bp.y-i])== typeid(Tower))&&
						(((Tower*)(&myItem[bp.x][bp.y-i]))->getBlocks()!=0)){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x][bp.y-i])== typeid(Piece))&&
						(((Piece*)(&myItem[bp.x][bp.y-i]))->getName()!=p.getInitial(' '))){
						res=false;
						break;
					}
				}
				break;
			case SOUTH:
				for(int i=0;i<=dis;i++)
				{
					if(bp.y+i<9){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x][bp.y+i])== typeid(Tower))&&
						(((Tower*)(&myItem[bp.x][bp.y+i]))->getBlocks()!=0)){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x][bp.y+i])== typeid(Piece))&&
						(((Piece*)(&myItem[bp.x][bp.y+i]))->getName()!=p.getInitial(' '))){
						res=false;
						break;
					}
				}
				break;
				case WEST:
				for(int i=0;i<=dis;i++)
				{
					if(bp.x-i>=0){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x-i][bp.y])== typeid(Tower))&&
						(((Tower*)(&myItem[bp.x-i][bp.y]))->getBlocks()!=0)){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x-i][bp.y])== typeid(Piece))&&
						(((Piece*)(&myItem[bp.x-i][bp.y]))->getName()!=p.getInitial(' '))){
						res=false;
						break;
					}
				}
				break;
				case EAST:
				for(int i=0;i<=dis;i++)
				{
					if(bp.x+i<9){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x+i][bp.y])== typeid(Tower))&&
						(((Tower*)(&myItem[bp.x+i][bp.y]))->getBlocks()!=0)){
						res=false;
						break;
					}
					if((typeid (myItem[bp.x-i][bp.y])== typeid(Piece))&&
						(((Piece*)(&myItem[bp.x-i][bp.y]))->getName()!=p.getInitial(' '))){
						res=false;
						break;
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
			if(c.getDirection()==WEST)
			{x-=c.getDistance();}
			else if(c.getDirection()==EAST)
			{x+=c.getDistance();}
			else if(c.getDirection()==NORTH)
			{y-=c.getDistance();}
			else if(c.getDirection()==SOUTH)
			{y+=c.getDistance();}
			myItem[x][y]=myItem[bp.x][bp.y];
			myItem[bp.x][bp.y]=Tower(0);
		}
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
		if(typeid(myItem[x][y])==typeid(Piece)&&(((Piece*)&myItem[x][y])->getName()==p.getInitial(' ')))
		{
			if(p.increaseBlocks(0)>=phase&&c.getDistance()==phase)
			{
				p.decreaseBlocks(phase);
				p.increasePoints(phase);
				Hand<Card> tempC=p.getHand();
				int i;
				for(i=0;i<5;i++)
					if(tempC[i]==c)
						break;
				myDeck+=tempC.play(i);
				myItem[x][y]=Tower(c);
				p.addPiece();
			}
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
	};
	void GameBoard::knockOffPiece(Player& p, const Card& c, const BoardPosition& bp);
	void GameBoard::unitTest();