#include <iostream>
#include "piece.h"
#include "board.h"
using namespace std;

void getInputs(int& intColumnOfPieceToMove, int& rowOfPieceToMove, int& intColumnOfPieceToGoTo, int& rowOfPieceToGoTo, bool whitesTurn);

int main() {
	
	gameManager game;
	int rowOfPieceToMove = -1;
	int intColumnOfPieceToMove = -1;
	int rowOfPieceToGoTo = -1;
	int intColumnOfPieceToGoTo = -1;
	
	do{
		game.printBoard();
		getInputs(intColumnOfPieceToMove, rowOfPieceToMove, intColumnOfPieceToGoTo, rowOfPieceToGoTo, game.isItWhitesTurn());

		// move pieces that the user wants 

		if(game.check_available(rowOfPieceToMove, intColumnOfPieceToMove, rowOfPieceToGoTo, intColumnOfPieceToGoTo)){
			game.movePiece(intColumnOfPieceToMove, rowOfPieceToMove, intColumnOfPieceToGoTo, rowOfPieceToGoTo);
			game.incMoveCount();
			game.changeTurn();
		}

		game.checkAndDoPromotion();
			
	}while(game.doesKingStillExist(WHITE) && game.doesKingStillExist(BLACK));

	game.printBoard();

	if(game.doesKingStillExist(WHITE)){
		cout << endl << "WHITE HAS WON!!!" << endl;
	}
	if(game.doesKingStillExist(BLACK)){
		cout << endl << "BLACK HAS WON!!!" << endl;
	}
	return 0;
};

void getInputs(int& intColumnOfPieceToMove, int& rowOfPieceToMove, int& intColumnOfPieceToGoTo, int& rowOfPieceToGoTo, bool whitesTurn){
	char columnOfPieceToMove = ' ';
	char columnOfPieceToGoTo = ' ';
	intColumnOfPieceToMove = -1;
	rowOfPieceToMove = -1;
	intColumnOfPieceToGoTo = -1;
	rowOfPieceToGoTo = -1;
	string initalInput = "";

		if(whitesTurn){

			do{
				cout << "column of the piece white wants to move: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				columnOfPieceToMove = initalInput.at(0);
				columnOfPieceToMove = tolower(columnOfPieceToMove);
				columnOfPieceToMove = columnOfPieceToMove - 97;
				intColumnOfPieceToMove = columnOfPieceToMove;
			}while(!(intColumnOfPieceToMove >= 0 && intColumnOfPieceToMove <=7));

			do{
				cout << "row of the piece white wants to move: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				rowOfPieceToMove = initalInput.at(0) - '0';
				rowOfPieceToMove = rowOfPieceToMove - 1;
			}while(!(rowOfPieceToMove >= 0 && rowOfPieceToMove <=7));

			do{
				cout << "column of the piece white wants to go to: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				columnOfPieceToGoTo = initalInput.at(0);
				columnOfPieceToGoTo = tolower(columnOfPieceToGoTo);
				columnOfPieceToGoTo = columnOfPieceToGoTo - 97;
				intColumnOfPieceToGoTo = columnOfPieceToGoTo;
			}while(!(intColumnOfPieceToGoTo >= 0 && intColumnOfPieceToGoTo <=7));

			do{
				cout << "row of the piece white wants to go to: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				rowOfPieceToGoTo = initalInput.at(0) - '0';
				rowOfPieceToGoTo = rowOfPieceToGoTo - 1;
			}while(!(rowOfPieceToGoTo >= 0 && rowOfPieceToGoTo <=7));

		}
		//black's turn
		else{
			do{
				cout << "column of the piece black wants to move: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				columnOfPieceToMove = initalInput.at(0);
				columnOfPieceToMove = tolower(columnOfPieceToMove);
				columnOfPieceToMove = columnOfPieceToMove - 97;
				intColumnOfPieceToMove = columnOfPieceToMove;
			}while(!(intColumnOfPieceToMove >= 0 && intColumnOfPieceToMove <=7));

			do{
				cout << "row of the piece black wants to move: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				rowOfPieceToMove = initalInput.at(0) - '0';
				rowOfPieceToMove = rowOfPieceToMove - 1;
			}while(!(rowOfPieceToMove >= 0 && rowOfPieceToMove <=7));

			do{
				cout << "column of the piece black wants to go to: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				columnOfPieceToGoTo = initalInput.at(0);
				columnOfPieceToGoTo = tolower(columnOfPieceToGoTo);
				columnOfPieceToGoTo = columnOfPieceToGoTo - 97;
				intColumnOfPieceToGoTo = columnOfPieceToGoTo;
			}while(!(intColumnOfPieceToGoTo >= 0 && intColumnOfPieceToGoTo <=7));

			do{
				cout << "row of the piece black wants to go to: ";
				cin >> initalInput;
				if(initalInput.length() > 1){
					continue;
				}
				rowOfPieceToGoTo = initalInput.at(0) - '0';
				rowOfPieceToGoTo= rowOfPieceToGoTo - 1;
			}while(!(rowOfPieceToGoTo >= 0 && rowOfPieceToGoTo <=7));
		}
}
