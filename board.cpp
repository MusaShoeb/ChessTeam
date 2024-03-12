#include <iostream>
#include "filename.h"
using namespace std;

int main() {
	
	gameManager game;

	while(!game.isCheckmate() and !game.isStalemate() and game.getMoveCount() < 50){

		game.incMoveCount();
	}

	return 0;
};


