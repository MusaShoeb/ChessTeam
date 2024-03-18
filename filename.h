#include <iostream>
using namespace std;
#include <cmath>

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
        void moveRook(&Piece rookToMove, int numOfSpaces, bool direction){
            if(direction){
              rookToMove.current_column += y_spaces;  
            }
            else{
                rookToMove.current_row  += x_spaces;
            }
        }
        void moveBishop(&Piece bishopToMove, int x_spaces, int y_spaces, bool direction){
            if(abs(x_spaces) == abs(y_spaces)){
                bishopToMove.current_column += y_spaces;
                bishopToMove.current_row += x_spaces;
            }
        }
        void movePawn(&Piece pawnToMove, int x_spaces, int y_spaces, bool direction){
            if((pawnToMove.getColor() == WHITE) && (pawnToMove.getRow() == 2)){
                if(int x_spaces <= 2){
                    pawnToMove.current_column += x_spaces;
                }
            }
            if((pawnToMove.getColor() == BLACK) && (pawnToMove.getRow() == 7)){
                if(int x_spaces >= -2){
                    pawnToMove.current_column += x_spaces;
                }
            }
            /*if(check_If_Piece_at_location){
                if(pawnToMove.getColor() == WHITE)){
                    if(x_spaces == 1 && (y_spaces == 1 || y_spaces == -1)){
                        pawnToMove += x_spaces;
                        pawnToMove += y_spaces;
                    }
                    
                }
            }*/
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
                for(int i = 0; i< x_spaces){
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
        // make sure to do the blank pieces (BLANK for piece type, NONE for color)
        Pieces board[8][8] = { 
                Pieces(BLACK, 1, ROOK, 0, 1), Pieces(BLACK, 0, KNIGHT, 0, 1),Pieces(BLACK, 0, BISHOP, 0, 1),Pieces(BLACK, 0, QUEEN, 0, 1),Pieces(BLACK, 0, KING, 0, 1),Pieces(BLACK, 0, BISHOP, 0, 1),Pieces(BLACK, 0, KNIGHT, 0, 1),Pieces(BLACK, 2, ROOK, 0, 0),
                Pieces(BLACK, 0, PAWN, 0, 2), Pieces(BLACK, 0, PAWN, 0, 2),Pieces(BLACK, 0, PAWN, 0, 2),Pieces(BLACK, 0, PAWN, 0, 2),Pieces(BLACK, 0, PAWN, 0, 2),Pieces(BLACK, 0, PAWN, 0, 2),Pieces(BLACK, 0, PAWN, 0, 2),Pieces(BLACK, 0, PAWN, 0, 0),
                Pieces(NONE, 0, BLANK, 0, 3), Pieces(NONE, 0, BLANK, 0, 3),Pieces(NONE, 0, BLANK, 0, 3),Pieces(NONE, 0, BLANK, 0, 3),Pieces(NONE, 0, BLANK, 0, 3),Pieces(NONE, 0, BLANK, 0, 3),Pieces(NONE, 0, BLANK, 0, 3),Pieces(NONE, 0, BLANK, 0, 0),
                Pieces(NONE, 0, BLANK, 0, 4), Pieces(NONE, 0, BLANK, 0, 4),Pieces(NONE, 0, BLANK, 0, 4),Pieces(NONE, 0, BLANK, 0, 4),Pieces(NONE, 0, BLANK, 0, 4),Pieces(NONE, 0, BLANK, 0, 4),Pieces(NONE, 0, BLANK, 0, 4),Pieces(NONE, 0, BLANK, 0, 0),
                Pieces(NONE, 0, BLANK, 0, 5), Pieces(NONE, 0, BLANK, 0, 5),Pieces(NONE, 0, BLANK, 0, 5),Pieces(NONE, 0, BLANK, 0, 5),Pieces(NONE, 0, BLANK, 0, 5),Pieces(NONE, 0, BLANK, 0, 5),Pieces(NONE, 0, BLANK, 0, 5),Pieces(NONE, 0, BLANK, 0, 0),
                Pieces(NONE, 0, BLANK, 0, 6), Pieces(NONE, 0, BLANK, 0, 6),Pieces(NONE, 0, BLANK, 0, 6),Pieces(NONE, 0, BLANK, 0, 6),Pieces(NONE, 0, BLANK, 0, 6),Pieces(NONE, 0, BLANK, 0, 6),Pieces(NONE, 0, BLANK, 0, 6),Pieces(NONE, 0, BLANK, 0, 0),
                Pieces(WHITE, 0, PAWN, 0, 7), Pieces(WHITE, 0, PAWN, 0, 7),Pieces(WHITE, 0, PAWN, 0, 7),Pieces(WHITE, 0, PAWN, 0, 7),Pieces(WHITE, 0, PAWN, 0, 7),Pieces(WHITE, 0, PAWN, 0, 7),Pieces(WHITE, 0, PAWN, 0, 7),Pieces(WHITE, 0, PAWN, 0, 0),
                Pieces(WHITE, 0, ROOK, 0, 8), Pieces(WHITE, 0, KNIGHT, 0, 8),Pieces(WHITE, 0, BISHOP, 0, 8),Pieces(WHITE, 0, QUEEN, 0, 8),Pieces(WHITE, 0, KING, 0, 8),Pieces(WHITE, 0, BISHOP, 0, 8),Pieces(WHITE, 0, KNIGHT, 0, 0),Pieces(WHITE, 0, ROOK, 0, 0),
                };
};
