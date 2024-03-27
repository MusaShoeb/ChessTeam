#include <iostream>
#include "piece.h"
#include "board.h"
using namespace std;

int main() {
	
	gameManager game;

	while(!game.isCheckmate() and !game.isStalemate() and game.getMoveCount() < 50){
		//game.printBoard();

		game.incMoveCount();
	}

	return 0;
};


