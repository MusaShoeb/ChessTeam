#include <iostream>
using namespace std;
#include <string>




void funcstart_funcmovement(string ChessBoard[8][8]) {   // and string x for movement and int y for timer 


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			string currentposition = ChessBoard[i][j];
			cout << ChessBoard[i][j] << endl; 

			// declaring white oppenent 

			if (currentposition == "a1") {
				ChessBoard[i][j] = "white rook";
			}
			else if (currentposition == "b1") {
				ChessBoard[i][j] = "white knight";
			}
			else if (currentposition == "c1") {
				ChessBoard[i][j] = "white bishop";
			}
			else if (currentposition == "d1") {
				ChessBoard[i][j] = "white queen";
			}
			else if (currentposition == "e1") {
				ChessBoard[i][j] = "white king";
			}
			else if (currentposition == "f1") {
				ChessBoard[i][j] = "white bishop";
			}
			else if (currentposition == "g1") {
				ChessBoard[i][j] = "white knight";
			}
			else if (currentposition == "h1") {
				ChessBoard[i][j] = "white rook";
			}


			/// White pawn printing 2nd row of board 


			else if (currentposition == "a2") {
				for (int x = 0; x < 8; x++) {
					ChessBoard[i][j + x] = "white pawn";
				}

			}

			// decalring black opponent 
			else if  (currentposition == "a8") {
				ChessBoard[i][j] = "black rook";
			}
			else if (currentposition == "b8") {
				ChessBoard[i][j] = "black knight";
			}
			else if (currentposition == "c8") {
				ChessBoard[i][j] = "black bishop";
			}
			else if (currentposition == "d8") {
				ChessBoard[i][j] = "black queen";
			}
			else if (currentposition == "e8") {
				ChessBoard[i][j] = "black king";
			}
			else if (currentposition == "f8") {
				ChessBoard[i][j] = "black rook";
			}
			else if (currentposition == "g8") {
				ChessBoard[i][j] = "black knight";
			}
			else if (currentposition == "h8") {
				ChessBoard[i][j] = "black rook";
			}


			/// Black pawn printing top 2nd row of board 


			else if (currentposition == "a7") {
				for (int x = 0; x < 8; x++) {
					ChessBoard[i][j + x] = "black pawn";
				}

			}
			
			

		}


	}


	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			cout << ChessBoard[x][y] << " ";
		}
		cout << endl; // printing out start peices from above function 
	}

	/////////////////////////////////////////////

	// movemnet 





// make this a start class // setting up board placment
//declaring positons matrix[0][0] = a8



// void movemnt
// 
// 	for (int i = 0, i < 8; i++) {
//for int j = 0, j < 8; j++){
//if (ChessBoard[i][j] == x) {
	// make move 
//}
//}
//}
// 
// 
// 
// 
// 
	//// User movemnet through the board,
	// when the peice moves how will coordinates reamin after piece is placed and coordinate and moved to a diffrent coordinate

	// the curretn value will be asssighned in a placeholder value while the tempory value remains, if tomporart leaves , placeholder gats reaasssighned back


}


// writing and array or vrctor of 2 in order to get a grid form
int main() {











	//string ChessBoard[8][8] = { {"a8","b8","c8","d8","e8","f8"}, // creating the board and placing users call coordinates
	// {"a7","b7","c7","d7","e7","f7"},
	// {"a6","b6","c6","d6","e6","f6"},
	// {"a5","b5","c5","d5","e5","f5"},
	// {"a4","b4","c4","d4","e4","f4"},
	// {"a3","b3","c3","d3","e3","f3"},
	//    {"a2","b2","c2","d2","e2","f2"},
	// {"a1","b1","c1","d1","e1","f1"} };


	string ChessBoard[8][8] = {
	{"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"}, // creating the board and placing users call coordinates
	{"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7"},
	{"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6"},
	{"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5"},
	{"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4"},
	{"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3"},
	{"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"},
	{"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"}
	};

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << ChessBoard[i][j] << " ";
		}
		cout << endl; // gives out the chess board in each position 
	}


	//string x;
	//cout << "enter the position to move at: " << endl;
	//cin >> x;   /// gathering user input 
	funcstart_funcmovement(ChessBoard); // ADD A   timer (y) and a movement postiont(x) to the parameters 




	///placing pieces on the board at their initail position


	return 0;
};


