#include"Game.h"
#include<iostream>
using std::cout;
using std::endl;
Game::Game(){
	/*reates the deck with the 64 action cards and the game board with initial placement of towers. 
	This class also creates the two players and hands them their five initial action cards from the deck*/
	Direction _d=WEST;
	string s="A";
	player[0]=Player(s);
	s="B";
	player[1]=Player(s);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=1;k<5;k++){
				deck+=Card(_d,k);
			}
		}
		_d=(Direction)(_d+1);
	}
	for(int i=0;i<4;i++){
		player[0].addPiece();
		player[1].addPiece();
		player[0].myHand+=deck.draw();
		player[1].myHand+=deck.draw();
	}
	player[0].myHand+=deck.draw();
	player[1].myHand+=deck.draw();
};
void Game::runGame(){
	
		// Print board and players
		int turn=0;
		int phase=1;
		Deck<Card> &tDeck=deck;
		GameBoard plateau=GameBoard(tDeck);
		do{
		std::cout<< "             Phase: "<< phase << endl << endl << player[0] << plateau << player[1];
		Player& currentPlayer = player[turn%2];
		//ask player what move to make
		cout<<"Player "<<currentPlayer.getName();
		BoardPosition bp;
		Card &c=Card();
		Action a = askPlayer(currentPlayer,bp,c);
		Hand<Card>& h = currentPlayer.getHand(); 
		try {
		switch (a) {
			case EXCHANGE:
				h.exchangeCards(deck);
				//std::cout<< "             Phase: "<< phase << endl << endl << player[0] << plateau << player[1];
				break;
			case BUILD:
				{
				std::cout<<"Choose a piece:"<<std::endl;
				Piece tempP[4];
				int count=0;
				char x='a';
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++)
					{
						if(((Piece*)plateau.myItem[i][j])->getName()==currentPlayer.getInitial(' '))
						{
							cout<<count+1<<": ";
							tempP[count++]=*((Piece*)plateau.myItem[i][j]);
							cout<<"("<<i<<","<<j+1<<")"<<endl;
							tempP[count-1].x=i;
							tempP[count-1].y=j;
						}
					}
				int numP=0;
				std::cin>>numP;
				bp.x=tempP[numP-1].getX();bp.y=tempP[numP-1].getY();
				std::cout<<"Choose a card:"<<std::endl;
				for(int i=0;i<5;i++)
					cout<<i+1<<": "<<h[i]<<endl;
				std::cin>>numP;
				c=h[numP-1];
				plateau.buildTower(currentPlayer,c,bp,phase);
				h += deck.draw();
				//std::cout<< "             Phase: "<< phase << endl << endl << player[0] << plateau << player[1];
				break;
				}
			case DEMOLISH:
				{
				std::cout<<"Choose a piece:"<<std::endl;
				Piece tempP[4];
				Card pay;
				char x='a';
				int count=0;
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++)
					{
						if(((Piece*)plateau.myItem[i][j])->getName()==currentPlayer.getInitial(' '))
						{
							cout<<count+1<<": ";
							tempP[count++]=*((Piece*)plateau.myItem[i][j]);
							cout<<"("<<i<<","<<j+1<<")"<<endl;
							tempP[count-1].x=i;
							tempP[count-1].y=j;
						}
					}
				cout<<count+1<<": ";
				cout<<"Base"<<endl;
				int numP=0;
				int numPP=0;
				std::cin>>numP;
				int tempCount=0;
				BoardPosition tempBP[36];
				if(numP==count+1)
				{
					cout<<"choose a colum:"<<endl;
						std::cin>>numPP;
						bp.y=numPP-1;
						//delete(plateau.myItem[0][numPP-1]);
						std::cout<<"Choose a card:"<<std::endl;
						for(int i=0;i<5;i++)
							cout<<i+1<<": "<<h[i]<<endl;
						std::cin>>numP;
						if(turn%2==0){
							bp.x=0;c.direction=SOUTH;}
						else
						{bp.x=8;c.direction=NORTH;}
						c=h[numP-1];
						Card temp=c;
						if(((Tower*)plateau.myItem[bp.x][bp.y])->getBlocks()>=0){
							if(((Tower*)plateau.myItem[bp.x][bp.y])->getBlocks()!=0&&c.getDistance()!=1)
								throw myException("illegalDemolish");
						temp.distance--;
						if(turn%2==0){
							bp.x=0;temp.direction=SOUTH;}
						else
						{bp.x=8;temp.direction=NORTH;}
						pay = askHowToPay( currentPlayer );
						if(pay.direction==c.direction&&pay.distance==c.distance)
							throw myException("illegalDemolish");
						plateau.demolishTower(currentPlayer, temp, pay, bp,phase);
						if(turn%2==0)
						{
						delete(plateau.myItem[0][numPP-1]);
						plateau.myItem[0][numPP-1]=new Tower(0);
						delete(plateau.myItem[bp.x+temp.distance][numPP-1]);
						plateau.myItem[bp.x+temp.distance][numPP-1]=new Piece(currentPlayer.getInitial('x'));
						}
						else
						{
						delete(plateau.myItem[8][numPP-1]);
						plateau.myItem[8][numPP-1]=new Tower(0);
						delete(plateau.myItem[bp.x-temp.distance][numPP-1]);
						plateau.myItem[bp.x-temp.distance][numPP-1]=new Piece(currentPlayer.getInitial('x'));
						}
						//c.distance++;
						//currentPlayer.removePiece();
						currentPlayer.removePiece();
						}

				}
				else
				{bp.x=tempP[numP-1].getX();bp.y=tempP[numP-1].getY();
				std::cout<<"Choose a card:"<<std::endl;
				for(int i=0;i<5;i++)
					cout<<i+1<<": "<<h[i]<<endl;
				std::cin>>numP;
				c=h[numP-1];
				pay = askHowToPay( currentPlayer );
				plateau.demolishTower(currentPlayer, c, pay, bp,phase);}
				for(numP=0;numP<h.cards.size();numP++)
					if (h.cards[numP].getDirection()==pay.getDirection()&&h.cards[numP].getDistance()==pay.getDistance())
						break;
				deck+=h.play(numP);
				int i;
				for(i=0;i<5;i++)
					if(h[i].getDirection()==c.getDirection() && h[i].getDistance()==c.getDistance())
						break;
				deck+=h.play(i);
				h+= deck.draw(); 
				h+= deck.draw(); // Need to replace 2 cards
					bool t=false;
					for(int i=0;i<9;++i){
						for(int j=0;j<9;++j)
							if(((Tower*)plateau.myItem[i][j])->getBlocks()==phase)
							{t=true;break;}
							if (t)break;
					}
					if(!t)phase++;
				break;
				}
			case ADD:
				{
				int numP;
				std::cout<<"Choose a card:"<<std::endl;
				for(int i=0;i<5;i++)
				cout<<i+1<<": "<<h[i]<<endl;
				std::cin>>numP;
				c=h[numP-1];
				std::cout<<"Choose a column(1-9):"<<std::endl;
				std::cin>>numP;
				bp.y=numP-1;
				Card temp=c;
				temp.distance--;
				if(turn%2==0){
							bp.x=0;temp.direction=SOUTH;}
						else
						{bp.x=8;temp.direction=NORTH;}
				if(plateau.isValidMove(currentPlayer, temp, bp)){
					if(((Tower*)plateau.myItem[bp.x][bp.y])->getBlocks()==0){
						//delete(plateau.myItem[bp.x][bp.y]);
						}
				else
					throw myException("illegalAdd");
					if(temp.getDirection()==NORTH)
					{bp.x-=temp.getDistance();}
					else if(temp.getDirection()==SOUTH)
					{bp.x+=temp.getDistance();}
					else if(temp.getDirection()==WEST)
					{bp.y-=temp.getDistance();}
					else if(temp.getDirection()==EAST)
					{bp.y+=temp.getDistance();}
					delete(plateau.myItem[bp.x][bp.y]);
					plateau.myItem[bp.x][bp.y]=new (Piece)(currentPlayer.removePiece());}
				else{
					//c.distance++;
					throw myException("illegalAdd");}
				//c.distance++;
				int i=0;
				for(i=0;i<5;i++)
					if(h[i].getDirection()==c.getDirection() && h[i].getDistance()==c.getDistance())
						break;
				deck+=h.play(i);
				h+=deck.draw();
				break;
				}
			case KNOCKOFF:
				{
				char x='a';
				std::cout<<"Choose a piece:"<<std::endl;
				Piece tempP[4];
				int count=0;
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++)
					{
						if(((Piece*)plateau.myItem[i][j])->getName()==currentPlayer.getInitial(' '))
						{
							cout<<count+1<<": ";
							tempP[count++]=*((Piece*)plateau.myItem[i][j]);
							cout<<"("<<i<<","<<j+1<<")"<<endl;
							tempP[count-1].x=i;
							tempP[count-1].y=j;
						}
					}
				int numP=0;
				std::cin>>numP;
				bp.x=tempP[numP-1].getX();bp.y=tempP[numP-1].getY();
				std::cout<<"Choose a card:"<<std::endl;
				for(int i=0;i<5;i++)
					cout<<i+1<<": "<<h[i]<<endl;
				std::cin>>numP;
				c=h[numP-1];
				plateau.knockOffPiece(currentPlayer, c, bp);
				deck+=h.play(numP-1);
				h += deck.draw();
				// Update other player
				player[(turn+1)%2].addPiece();
				break;
				}
			case MOVE:
				char x='a';
				std::cout<<"Choose a piece:"<<std::endl;
				Piece tempP[4];
				int count=0;
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++)
					{
						if(((Piece*)plateau.myItem[i][j])->getName()==currentPlayer.getInitial(' '))
						{
							cout<<count+1<<": ";
							tempP[count++]=*((Piece*)plateau.myItem[i][j]);
							cout<<"("<<i<<","<<j+1<<")"<<endl;
							tempP[count-1].x=i;
							tempP[count-1].y=j;
						}
					}
				int numP=0;
				std::cin>>numP;
				bp.x=tempP[numP-1].getX();bp.y=tempP[numP-1].getY();
				std::cout<<"Choose a card:"<<std::endl;
				for(int i=0;i<5;i++)
					cout<<i+1<<": "<<h[i]<<endl;
				std::cin>>numP;
				c=h[numP-1];
				if(plateau.isValidMove(currentPlayer,c,bp))
				plateau.move(currentPlayer, c, bp);
				int i;
				for(i=0;i<5;i++)
					if(h[i].getDirection()==c.getDirection() && h[i].getDistance()==c.getDistance())
						break;
				deck+=h.play(i);
				h += deck.draw();
				break;
		}
		turn++; 
		}
		catch (myException t){
				// display a message explaining why the proposed 
				// action is invalid.
				// the player must select another action.
			cout<<t.toString()<<endl;
				}
} while(phase!=4); //(!endOfgame());
//cout << "Phase: << phase << endl << endl << player[0] << plateau << player[1];

};