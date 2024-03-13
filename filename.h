#include <iostream>
using namespace std;

enum piece {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, BLANK}; // TYPE OF PIECES
enum color {BLACK, WHITE, NONE}; // COLOR OF PIECE

class Pieces{
    
    public:
        Pieces(color the_Color, int number_Of_Piece, piece type_Of_Piece , int starting_ROW , int starting_column){
            pieceType = type_Of_Piece;
            colorType = the_Color;
            piece_Number = number_Of_Piece;
            current_row = starting_ROW;
            current_column = starting_column;
        }
        piece getPiece(){
            return pieceType;
        }
        color getColor(){
            return colorType;
        }
        int getNumber(){
            return piece_Number;
        }
        int getColumn(){
            return current_column;
        }
        int getRow(){
            return current_row;
        }
        void setRow(int desired_Row){
            current_row = desired_Row;
        }
        void setColumn(int desired_Column){
            current_column = desired_Column;
        }
        void setPiece(piece desired_Piece){
            pieceType = desired_Piece;
        }
    private:
        piece pieceType;
        color colorType;
        int piece_Number;
        int current_column;
        int current_row;
};

class gameManager{

    public:
        // constructor
        gameManager(){
            
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
                 cout << board[i][j];
             }
             cout << endl;
        }

        bool isCheckmate(){
            
            return false;
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
        // make sure to do the blank pieces (BLANK for piece type, NONE for color)
        Pieces board[8][8] = { 
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                Pieces(WHITE, 1, ROOK, 1, 1), Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),Pieces(WHITE, 1, ROOK, 1, 1),
                };
 
};
