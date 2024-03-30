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

		//whites turn
		if(/* game.whitesTurn */true){
			do{
				cout << "column of the piece white wants to move: ";
				cin >> columnOfPieceToMove;
				columnOfPieceToMove = tolower(columnOfPieceToMove);
				columnOfPieceToMove = columnOfPieceToMove - 97;
				intColumnOfPieceToMove = columnOfPieceToMove;
			}while(!(intColumnOfPieceToMove >= 0 && intColumnOfPieceToMove <=7));

			do{
				cout << "row of the piece white wants to move: ";
				cin >> rowOfPieceToMove;
				rowOfPieceToMove = rowOfPieceToMove - 1;
			}while(!(rowOfPieceToMove >= 0 && rowOfPieceToMove <=7));

			do{
				cout << "column of the piece white wants to go to: ";
				cin >> columnOfPieceToGoTo;
				columnOfPieceToGoTo = tolower(columnOfPieceToGoTo);
				columnOfPieceToGoTo = columnOfPieceToGoTo - 97;
				intColumnOfPieceToGoTo = columnOfPieceToGoTo;
			}while(!(intColumnOfPieceToGoTo >= 0 && intColumnOfPieceToGoTo <=7));

			do{
				cout << "row of the piece white wants to go to: ";
				cin >> rowOfPieceToGoTo;
				rowOfPieceToGoTo = rowOfPieceToGoTo - 1;
			}while(!(rowOfPieceToGoTo >= 0 && rowOfPieceToGoTo <=7));

			cout << intColumnOfPieceToMove << rowOfPieceToMove << intColumnOfPieceToGoTo << rowOfPieceToGoTo;
		}
		//black's turn
		else{
			do{
				cout << "column of the piece black wants to move: ";
				cin >> columnOfPieceToMove;
				columnOfPieceToMove = tolower(columnOfPieceToMove);
				columnOfPieceToMove = columnOfPieceToMove - 97;
				intColumnOfPieceToMove = columnOfPieceToMove;
			}while(!(intColumnOfPieceToMove >= 0 && intColumnOfPieceToMove <=7));

			do{
				cout << "row of the piece black wants to move: ";
				cin >> rowOfPieceToMove;
				rowOfPieceToMove = rowOfPieceToMove - 1;
			}while(!(rowOfPieceToMove >= 0 && rowOfPieceToMove <=7));

			do{
				cout << "column of the piece black wants to go to: ";
				cin >> columnOfPieceToGoTo;
				columnOfPieceToGoTo = tolower(columnOfPieceToGoTo);
				columnOfPieceToGoTo = columnOfPieceToGoTo - 97;
				intColumnOfPieceToGoTo = columnOfPieceToGoTo;
			}while(!(intColumnOfPieceToGoTo >= 0 && intColumnOfPieceToGoTo <=7));

			do{
				cout << "row of the piece black wants to go to: ";
				cin >> rowOfPieceToGoTo;
				rowOfPieceToGoTo = rowOfPieceToGoTo - 1;
			}while(!(rowOfPieceToGoTo >= 0 && rowOfPieceToGoTo <=7));

			cout << intColumnOfPieceToMove << rowOfPieceToMove << intColumnOfPieceToGoTo << rowOfPieceToGoTo;	
		}

		//game.attemptMove(intColumnOfPieceToMove,rowOfPieceToMove,intColumnOfPieceToGoTo,rowOfPieceToGoTo)
		//game.incMoveCount();
	}while(/*
		!game.isCheckmate() and !game.isStalemate() and game.getMoveCount() < 50*/
		false
		);

	return 0;
};


