#include <iostream>
//#include "piece.h"
//#include "board.h"
using namespace std;

int main() {
	
	//gameManager game;
	int rowOfPieceToMove = -1;
	char columnOfPieceToMove = ' ';
	int intColumnOfPieceToMove;
	int rowOfPieceToGoTo = -1;
	char columnOfPieceToGoTo = ' ';
	int intColumnOfPieceToGoTo = -1;

	do{
		//game.printBoard();
		if(
			/*
			game.whitesTurn */
			true){
			cout << "column of the piece white wants to move: ";
			cin >> columnOfPieceToMove;
			columnOfPieceToMove = tolower(columnOfPieceToMove);
			columnOfPieceToMove = columnOfPieceToMove - 97;
			intColumnOfPieceToMove = columnOfPieceToMove;

			cout << "row of the piece white wants to move: ";
			cin >> rowOfPieceToMove;
			rowOfPieceToMove = rowOfPieceToMove - 1;

			cout << "column of the piece white wants to go to: ";
			cin >> columnOfPieceToGoTo;
			columnOfPieceToGoTo = tolower(columnOfPieceToGoTo);
			columnOfPieceToGoTo = columnOfPieceToGoTo - 97;
			intColumnOfPieceToGoTo = columnOfPieceToGoTo;

			cout << "row of the piece white wants to go to: ";
			cin >> rowOfPieceToGoTo;
			rowOfPieceToGoTo = rowOfPieceToGoTo - 1;

			cout << intColumnOfPieceToMove << rowOfPieceToMove << intColumnOfPieceToGoTo << rowOfPieceToGoTo;
		}
			
		//game.incMoveCount();
	}while(/*
		!game.isCheckmate() and !game.isStalemate() and game.getMoveCount() < 50*/
		false
		);

	return 0;
};


