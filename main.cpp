#include <iostream>
#include "piece.h"
#include "board.h"
using namespace std;

void getInputs(int& intColumnOfPieceToMove, int& rowOfPieceToMove, int& intColumnOfPieceToGoTo, int& rowOfPieceToGoTo, bool whitesTurn);

int main() {
	
	gameManager game;
	gameManager TEMP;
	int rowOfPieceToMove = -1;
	int intColumnOfPieceToMove = -1;
	int rowOfPieceToGoTo = -1;
	int intColumnOfPieceToGoTo = -1;

	do{
		game.printBoard();
		TEMP = game;
		getInputs(intColumnOfPieceToMove, rowOfPieceToMove, intColumnOfPieceToGoTo, rowOfPieceToGoTo, game.isItWhitesTurn());

		// move pieces that the user wants 
		if(game.check_available(rowOfPieceToMove, intColumnOfPieceToMove, rowOfPieceToGoTo, intColumnOfPieceToGoTo)){

			TEMP.movePiece(intColumnOfPieceToMove, rowOfPieceToMove, intColumnOfPieceToGoTo, rowOfPieceToGoTo);
			if(TEMP.isCheck(WHITE) && TEMP.isItWhitesTurn()){ // does white put themselves in check on their move
				continue;
			}
			if(TEMP.isCheck(BLACK) && !TEMP.isItWhitesTurn()){ // does black put themselves in check on their move
				continue;
			}
			if(game.isCheck(WHITE) && TEMP.isCheck(WHITE)){ // does white resolve their check
				continue;
			}
			if(game.isCheck(BLACK) && TEMP.isCheck(BLACK)){ // does black resolve their check
				continue;
			}

			game.movePiece(intColumnOfPieceToMove, rowOfPieceToMove, intColumnOfPieceToGoTo, rowOfPieceToGoTo);
			game.incMoveCount();
			game.changeTurn();
		}
			
		// this is a temp game loop 
	}while(game.getMoveCount() != 10);

	return 0;
};

void getInputs(int& intColumnOfPieceToMove, int& rowOfPieceToMove, int& intColumnOfPieceToGoTo, int& rowOfPieceToGoTo, bool whitesTurn){
	char columnOfPieceToMove = ' ';
	char columnOfPieceToGoTo = ' ';

		if(whitesTurn){
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
		}
}
