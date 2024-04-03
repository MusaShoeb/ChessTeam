#include <iostream>
#include "piece.h"
#include "board.h"
using namespace std;

int main() {
	
	gameManager game;
	int rowOfPieceToMove = -1;
	char columnOfPieceToMove = ' ';
	int intColumnOfPieceToMove;
	int rowOfPieceToGoTo = -1;
	char columnOfPieceToGoTo = ' ';
	int intColumnOfPieceToGoTo = -1;

	do{
		game.printBoardSpaces();
		game.printBoard();
		game.printBoardTEST();
		//whites turn first
		if( game.isItWhitesTurn() ){
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

			//uncommented below to see what the gets passed to the attemptMoveFunction
			//cout << intColumnOfPieceToMove << rowOfPieceToMove << intColumnOfPieceToGoTo << rowOfPieceToGoTo;

			// move pieces that the user wants 
			if(game.check_available(rowOfPieceToMove, columnOfPieceToMove, rowOfPieceToGoTo, intColumnOfPieceToGoTo)){
				game.movePiece(intColumnOfPieceToMove, rowOfPieceToMove, intColumnOfPieceToGoTo, rowOfPieceToGoTo);
				// change to Black's turn for the next do-while loop iteration
				game.changeTurn();
			}
			// increase the counter
			game.incMoveCount();

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
			
			// move pieces that the user wants 
			if(game.check_available(rowOfPieceToMove, columnOfPieceToMove, rowOfPieceToGoTo, intColumnOfPieceToGoTo)){
				game.movePiece(intColumnOfPieceToMove, rowOfPieceToMove, intColumnOfPieceToGoTo, rowOfPieceToGoTo);
				// change to white's turn for the next do-while loop iteration
				game.changeTurn();
			}
			
			// increase the counter
			game.incMoveCount();
			
		}

		// this is a temp game loop 
	}while(game.getMoveCount() != 10);

	return 0;
};


