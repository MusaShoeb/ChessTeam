#include <iostream>
using namespace std;
#include <cmath>
class gameManager{

    public:
        // constructor
        gameManager(){
            printBoard();
        }

        bool isItWhitesTurn(){
            return whitesTurn;
        }

        void changeTurn(){
            whitesTurn = !whitesTurn;
        }
        
        void printBoard(){
         for(int i = 0; i < 8; i ++){
             for(int j = 0; j < 8; j++){
                cout << board[i][j].getPiece();
             }
             cout << endl;
            }
        }

        bool isCheckmate(){
            
            return false;
        }
        bool check_available(&Piece currentPiece, int x_spaces, int y_spaces){
            if(currentPiece.getPiece() ==  ROOK)
                for(int i = 0; i < x_spaces){
                    if(direction){
                        board[i][j];
                    }
                }
                for(){
                    
                }
            
        } 
        bool isStalemate(){
            
            return false;
        }

        // do we want one string containing the move to be the argument (like now), or for the main to parse it, and pass row, column, piece, as arguments?
        void attemptMove(string move){
            //more methods in here? one for each piece?
        }

        // these two are mostly for testing
        void incMoveCount(){
            moveCount++;
        }
        int getMoveCount(){
            return moveCount;
        }

    private:
        bool whitesTurn = true;
        int moveCount = 0;
        // todo
        // order goes: color, piece number, piece type, row, column
        // make sure to do the blank pieces (BLANK for piece type, NONE fo color)
        Pieces board[8][8] = {
                Pieces(BLACK, 1, ROOK, 7, 0), Pieces(BLACK, 0, KNIGHT, 7, 1),   Pieces(BLACK, 0, BISHOP, 7, 2), Pieces(BLACK, 0, QUEEN, 7, 3),  Pieces(BLACK, 0, KING, 7, 4),   Pieces(BLACK, 0, BISHOP, 7, 5), Pieces(BLACK, 0, KNIGHT, 7, 6), Pieces(BLACK, 2, ROOK, 7, 7),
                Pieces(BLACK, 0, PAWN, 6, 0), Pieces(BLACK, 0, PAWN,   6, 1),   Pieces(BLACK, 0, PAWN,   6, 2), Pieces(BLACK, 0, PAWN,  6, 3),  Pieces(BLACK, 0, PAWN, 6, 4),   Pieces(BLACK, 0, PAWN,   6, 5), Pieces(BLACK, 0, PAWN,   6, 6), Pieces(BLACK, 0, PAWN, 6, 7),
                Pieces(NONE, 0, BLANK, 5, 0), Pieces(NONE, 0, BLANK,   5, 1),   Pieces(NONE, 0, BLANK,   5, 2), Pieces(NONE, 0, BLANK,  5, 3),  Pieces(NONE, 0, BLANK, 5, 4),   Pieces(NONE, 0, BLANK,   5, 5), Pieces(NONE, 0, BLANK,   5, 6), Pieces(NONE, 0, BLANK, 5, 7),
                Pieces(NONE, 0, BLANK, 4, 0), Pieces(NONE, 0, BLANK,   4, 1),   Pieces(NONE, 0, BLANK,   4, 2), Pieces(NONE, 0, BLANK,  4, 3),  Pieces(NONE, 0, BLANK, 4, 4),   Pieces(NONE, 0, BLANK,   4, 5), Pieces(NONE, 0, BLANK,   4, 6), Pieces(NONE, 0, BLANK, 4, 7),
                Pieces(NONE, 0, BLANK, 3, 0), Pieces(NONE, 0, BLANK,   3, 1),   Pieces(NONE, 0, BLANK,   3, 2), Pieces(NONE, 0, BLANK,  3, 3),  Pieces(NONE, 0, BLANK, 3, 4),   Pieces(NONE, 0, BLANK,   3, 5), Pieces(NONE, 0, BLANK,   3, 6), Pieces(NONE, 0, BLANK, 3, 7),
                Pieces(NONE, 0, BLANK, 2, 0), Pieces(NONE, 0, BLANK,   2, 1),   Pieces(NONE, 0, BLANK,   2, 2), Pieces(NONE, 0, BLANK,  2, 3),  Pieces(NONE, 0, BLANK, 2, 4),   Pieces(NONE, 0, BLANK,   2, 5), Pieces(NONE, 0, BLANK,   2, 6), Pieces(NONE, 0, BLANK, 2, 7),
                Pieces(WHITE, 0, PAWN, 1, 0), Pieces(WHITE, 0, PAWN,   1, 1),   Pieces(WHITE, 0, PAWN,   1, 2), Pieces(WHITE, 0, PAWN,  1, 3),  Pieces(WHITE, 0, PAWN, 1, 4),   Pieces(WHITE, 0, PAWN,   1, 5), Pieces(WHITE, 0, PAWN,   1, 6), Pieces(WHITE, 0, PAWN, 1, 7),
                Pieces(WHITE, 0, ROOK, 0, 0), Pieces(WHITE, 0, KNIGHT, 0, 1),   Pieces(WHITE, 0, BISHOP, 0, 2), Pieces(WHITE, 0, QUEEN, 0, 3),  Pieces(WHITE, 0, KING, 0, 4),   Pieces(WHITE, 0, BISHOP, 0, 5), Pieces(WHITE, 0, KNIGHT, 0, 6), Pieces(WHITE, 0, ROOK, 0, 7),
                };
};